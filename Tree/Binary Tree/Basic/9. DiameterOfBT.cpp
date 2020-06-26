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

void printLevelOrder(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        //Enqueue left child
        if(temp->left)
            q.push(temp->left);

        //Enqueue right child
        if(temp->right)
            q.push(temp->right);
    }
}

int height(node* root)
{
    if(root == NULL)
        return 0;

    int lht = height(root->left);
    int rht = height(root->right);

    return 1 + max(lht, rht);
}

int diameterOfBinaryTree(node* root)
{
    if(root == NULL)
        return 0;

    int lht = height(root->left);
    int rht = height(root->right);

    int lDiameter = diameterOfBinaryTree(root->left);
    int rDiameter = diameterOfBinaryTree(root->right);

    return max(1+lht+rht, max(lDiameter, rDiameter));
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Level Order\n";
    printLevelOrder(root);

    cout<<"\nDiameter of Binary Tree : \n";
    cout<<diameterOfBinaryTree(root);
}
