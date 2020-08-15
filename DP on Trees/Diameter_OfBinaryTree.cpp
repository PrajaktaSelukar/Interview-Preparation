#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	node* left;
	node* right;
	int key;
};

struct node* newnode(int value)
{
	struct node* node = new struct node;
	node->key = value;
	node->left = NULL;
	node->right = NULL;
	
	return node; 
}

struct node* insert(struct node* node, int value)
{
	if(node == NULL)
		return newnode(value);
	
	if(value < node->key)
		node->left = insert(node->left, value);
	
	else
		node->right = insert(node->right, value);
	
	return node;		
}

int DiameterOfTree(node* root, int& res)
{
	if(root == NULL)
		return 0;
	
	int l = DiameterOfTree(root->left, res);
	int r = DiameterOfTree(root->right, res);
	
	int temp = 1 + max(l, r);
	int ans = max(temp, 1+l+r);
	res = max(res, ans);
	
	return temp;  	
}

int main()
{
	struct node* root = NULL;
	root = insert(root,5);
	root=insert(root,6);
	root=insert(root,7);
	root=insert(root,3);
	root=insert(root,2);
	root=insert(root,4);
	root=insert(root,8);
	//printLevelorder(root);
	
	int res=INT_MIN;
	int temp = DiameterOfTree(root, res);
	cout<<res;
}
