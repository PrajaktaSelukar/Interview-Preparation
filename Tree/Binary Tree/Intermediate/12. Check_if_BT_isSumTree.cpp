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

int sum(node* root)
{
    if(root == NULL)
        return 0;

    else if(root->left==NULL && root->right==NULL)
        return root->data;

    else
        return 2*(root->data);
}

int checkSumTree(node* root)
{
    if(root == NULL)
        return 1;

    if(root->left == NULL && root->right == NULL)
        return 1;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int total = leftSum + rightSum;

    if(total == root->data)
    {
        if(checkSumTree(root->left) && checkSumTree(root->right))
            return 1;
    }

    return 0;
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nCheck if Binary Tree is Sum Tree or not\n\n";

    if(checkSumTree(root))
        cout<<"Yes, it is a Sum Tree";

    else
        cout<<"No, it is not a Sum Tree";
}
