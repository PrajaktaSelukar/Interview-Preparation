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

void preorder(node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool searchKey(node* root, int key)
{
    node* curr = root;

    while(curr != NULL)
    {
        if(key < curr->data)
            curr = curr->left;
        else if(key > curr->data)
            curr = curr->right;

        else
            return true;
    }
    return false;
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

    cout<<"\n\nEnter a key to be searched : ";
    int key;
    cin>>key;

    if(searchKey(root, key) == true)
        cout<<"\nKey Found\n";
    else
        cout<<"\nKey not found\n";
}
