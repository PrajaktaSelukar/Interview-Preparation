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

void traverse(node* root, int level, int* maxlevel)
{
    if(root == NULL)
        return;

    if(*maxlevel < level)
    {
        cout<<root->data<<" ";
        *maxlevel = level;
    }

    traverse(root->left, level+1, maxlevel);
    traverse(root->right, level+1, maxlevel);
}

void printLeftView(node* root)
{
    int maxlevel = 0;
    traverse(root, 1, &maxlevel);
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Left Side View of Binary Tree\n";
    printLeftView(root);
}
