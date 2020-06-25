#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newnode(int key)
{
    Node* temp = new struct Node;
    temp->data =key;
    temp->left =NULL;
    temp->right = NULL;

    return temp;
}

Node* insertLevelOrder(int arr[], Node* node, int i, int n)
{
    if(i < n)
    {
        Node* temp = newnode(arr[i]);
        node = temp;

        node->left = insertLevelOrder(arr, node->left, 2*i+1, n);

        node->right = insertLevelOrder(arr, node->right, 2*i+2, n);
    }
    return node;
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void printLevelOrder(Node* root)
{
    queue<node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		struct node* n = q.front();
    	q.pop();
    	
		if(q.empty())
		{
    		cout<<endl;
    		break;
    	}

    	if(n==NULL && !q.empty())
		{
        	q.push(NULL);
        	cout<<endl;
    	}

    	else
		{
    		cout<<n->data<<" ";
    		
			if(n->left!=NULL)
        		q.push(n->left);
    		
			if(n->right!=NULL)
        		q.push(n->right);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    Node* root = insertLevelOrder(arr, root, 0, n);
    
    cout<<"\n\nPrint Level Order traversal of tree\n";
    printLevelOrder(root);
    
    cout<<"\n\nPrint Inorder traversal of tree\n";
	inorder(root);
}
