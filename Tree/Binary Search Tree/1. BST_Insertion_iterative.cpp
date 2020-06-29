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

void insertion(node* &root, int key)
{
    if(root == NULL)
    {
    	root = newnode(key);
        return;
    }
	
	node* curr = root;
    node* parent = NULL ;

    while(curr != NULL)
    {
        parent = curr;

        if(key < curr->data)
            curr = curr->left;

        else
            curr = curr->right;
    }

    if(key < parent->data)
        parent->left = newnode(key);

    else
    	parent->right = newnode(key);
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
        insertion(root, arr[i]);
    }

    cout<<"\n\nPrint Inorder traverse\n";
    inorder(root);
}
