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

bool is_present(node* root, int key)
{
    if(root == NULL)
        return false;

    if(root->data == key || is_present(root->left, key) || is_present(root->right, key))
        return true;

    return false;
}

node* find_lca(node* root, int a, int b)
{
    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    node* leftSearch = find_lca(root->left, a, b);
    node* rightSearch = find_lca(root->right, a, b);

    if(leftSearch == NULL)
        return rightSearch;

    if(rightSearch == NULL)
        return leftSearch;

    return root; //when both are not NULL
}

int lca(node* root, int a, int b)
{
    if(is_present(root, a) && is_present(root, b))
    {
        return find_lca(root, a, b)->data;
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nEnter two nodes to find their Lowest common ancestor : ";
    int a, b;
    cin>>a>>b;

    cout<<"\nLeast common ancestor : "<<lca(root, a, b);
}
