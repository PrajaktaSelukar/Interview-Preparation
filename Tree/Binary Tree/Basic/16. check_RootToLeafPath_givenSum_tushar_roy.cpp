#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

node* newnode(int key)
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
        cout<<"Enter the children (or -1) for node with data as "<<temp->data<<" : ";
        int data1;
        int data2;
        cin>>data1>>data2;

        if(data1!=-1)
        {
            temp->left  = new node;
            temp->left->data = data1;
            q.push(temp->left);
        }
        else
        {
            temp->left = NULL;
        }

        if(data2!=-1)
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

bool rootToLeafPathSum(node* root, int sum, vector<int> &result)
{
    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == sum)
        {
            result.push_back(root->data);
            return true;
        }
    }

    if(rootToLeafPathSum(root->left, sum-(root->data), result ))
    {
        result.push_back(root->data);
        return true;
    }

    if(rootToLeafPathSum(root->right, sum-(root->data), result))
    {
        result.push_back(root->data);
        return true;
    }
    return false;
}

int main()
{
    node* root;
    root = buildTree();
    printLevelOrder(root);

    cout<<"\nEnter a number : ";
    int sum;
    cin>>sum;
    vector<int> result;

    if(rootToLeafPathSum(root, sum, result))
        cout<<"\nYes, Root to Leaf path sum is equal to the given number\n";
    else
        cout<<"\nNo, Root to Leaf path sum is not equal to the given number\n";

    for(auto it=result.begin(); it!=result.end(); it++)
    {
        cout<<*it<<" ";
    }
}
