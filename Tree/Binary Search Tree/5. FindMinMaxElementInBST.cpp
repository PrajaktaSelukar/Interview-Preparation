#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newnode(int key)
{
    node* temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int key)
{
    if(root == NULL)
    {
        return newnode(key);
    }

    if(key < root->data)
        root->left = insert(root->left, key);

    if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int findMax(node* root)
{
    if(root == NULL)
        return INT_MIN;

    while(root->right != NULL)
        root = root->right;

    return root->data;
}

int findMin(node* root)
{
    if(root == NULL)
        return INT_MAX;

    while(root->left != NULL)
        root = root->left;

    return root->data;
}

int main()
{
    node* root = NULL;

    int n;
    cout<<"Enter no of nodes to be entered(n) : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        root = insert(root, arr[i]);
    }

    cout<<"\n\nPrint Inorder traverse\n";
    inorder(root);

    cout<<"\n\nMinimum element in BST : "<<findMin(root);

    cout<<"\n\nMaximum element in BST : "<<findMax(root);
}
