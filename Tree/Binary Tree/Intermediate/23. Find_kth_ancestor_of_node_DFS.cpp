#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

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

node* temp = NULL;
node* kthAncestorDFS(node* root, int node, int &k)
{
    if(root == NULL)
        return NULL;

    if( root->data == node || (temp = kthAncestorDFS(root->left, node, k)) || (temp = kthAncestorDFS(root->right, node, k)) )
    {
        if(k > 0)
            k--;

        else if(k == 0)
        {
            cout<<root->data;

            return NULL;
        }

        return root;
    }
}

node* kthAncestor(node* root, int a, int k)
{
    node* parent = kthAncestorDFS(root, a, k);

    if(parent)
        cout<<"-1";
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nEnter value and k(position) to find the kth Ancestor of node : ";
    int a, k;
    cin>>a>>k;

    cout<<"\nkth ancestor : ";
    kthAncestor(root, a, k);
}
