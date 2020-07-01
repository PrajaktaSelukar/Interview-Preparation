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

void searchKey(node* root, int key)
{
    if(root == NULL)
    {
        cout<<"Key not found\n";
        return;
    }


    if(root->data == key)
    {
        cout<<"Key found\n";
        return;
    }

    if(key < root->data)
        searchKey(root->left, key);

    else if(key > root->data)
        searchKey(root->right, key);

}

void floorCeil(node* root, node* &ceil, node* &floor, int key)
{
    if(root == NULL)
        return;

    if(root->data == key)
    {
        floor=root;
        ceil=root;
        return;
    }

    else if(key < root->data )
    {
        ceil = root;
        floorCeil(root->left, ceil, floor, key);
    }

    else
    {
        floor = root;
        floorCeil(root->right, ceil, floor, key);
    }
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

    cout<<"\n\n";

    for(int key=1; key<15; key++)
    {
        node* floor=NULL;
        node* ceil=NULL;
        floorCeil(root, ceil, floor, key);
        cout<<key<<" --> ";
        cout<<"Floor is "<<(floor ? floor->data : -1);
        cout<<" Ceil is "<<(ceil ? ceil->data : -1)<<endl;
    }
}
