#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node*buildTree()
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

void printLeftBoundary(node* root)
{
    if(root == NULL)
        return;

    if(root->left)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(node* root)
{
    if(root == NULL)
        return;

    if(root->right)
    {
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }
}

void printLeaves(node* root)
{
    if(root == NULL)
        return;

    printLeaves(root->left);

    if(root->left == NULL & root->right == NULL)
        cout<<root->data<<" ";

    printLeaves(root->right);
}

void printBoundary(node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";

    //print Left Boundary
    printLeftBoundary(root->left);

    //print Leaves
    printLeaves(root->left);
    printLeaves(root->right);

    //print Right Boundary
    printLeftBoundary(root->right);
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Boundary Traversal of Binary Tree\n";
    printBoundary(root);
}
