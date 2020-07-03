#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node*left;
    struct node*right;
};

node* newnode(char key)
{
    node* temp = new struct node;
    temp->data =key;
    temp->left =NULL;
    temp->right = NULL;

    return temp;
}

struct node* buildTree()
{
    struct node*root = new node;
    cout<<"Enter Root's Data : ";
    cin>>root->data;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {

        struct node*temp = q.front();
        q.pop();
        cout<<"Enter the children (or #) for node with data as "<<temp->data<<" : ";
        char data1;
        char data2;
        cin>>data1>>data2;

        if(data1!='#')
        {
            temp->left  = new node;
            temp->left->data = data1;
            q.push(temp->left);
        }
        else
        {
            temp->left = NULL;
        }

        if(data2!='#')
        {
            temp->right = new node;
            temp->right->data = data2;
            q.push(temp->right);
        }
        else
        {
            temp->right = NULL;
        }
    }
    return root;
}

void printLevelOrder(node* root)
{
    queue<node*> q;

q.push(root);
q.push(NULL);

while(!q.empty()){


    struct node* n = q.front();
    q.pop();
    if(q.empty()){
    cout<<endl;
    break;
    }

    if(n==NULL && !q.empty())
    {
        q.push(NULL);
        cout<<endl;
    }

    else{
    cout<<n->data<<" ";
    if(n->left!=NULL)
        q.push(n->left);
    if(n->right!=NULL)
        q.push(n->right);
        }
    }
}

unordered_set<string> subtrees;

string dupSubtree(node* root)
{
    string s="";

    if(root == NULL)
        return s+"$";

    //If left subtree has a duplicate subtree
    string lStr = dupSubtree(root->left);
    if(lStr.compare(s)== 0)
        return s;

    string rStr = dupSubtree(root->right);
    if(rStr.compare(s)== 0)
        return s;

    //serialize the current subtree
    s = s + root->data + lStr + rStr;
    cout<<s<<" ";

    //if current subtree already exist in hashtable
    if(s.length() > 3 && subtrees.find(s) != subtrees.end())
        return "";

    subtrees.insert(s);
    return s;
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nLevel order traversal \n";
    printLevelOrder(root);

    cout<<"\n------Check if a Binary Tree has duplicate subtree of size 2 or more------\n";
    string str = dupSubtree(root);

    if(str.compare("") == 0)
        cout<<"\nYes, duplicate subtrees exist";
    else
        cout<<"\nNo, duplicate subtrees do not exist";
}
