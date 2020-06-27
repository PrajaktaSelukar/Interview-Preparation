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

bool checkIdentical(node* root1, node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;

    if(root1==NULL || root2==NULL)
        return false;

    return ( root1->data == root2->data
            && checkIdentical(root1->left, root2->left)
            && checkIdentical(root1->right, root2->right));,m
}

bool checkSubtreeOfAnotherTree(node* root1, node* root2)
{
    if(root1 == NULL) // subtree can be empty
        return true;

    if(root2 == NULL) // supertree cannot be empty
        return false;

    if(checkIdentical(root1, root2))
        return true;

    return ( checkSubtreeOfAnotherTree(root1, root2->left) || checkSubtreeOfAnotherTree(root1, root2->right) );
}

int main()
{
    cout<<"Create first binary tree\n";
    node* root1;
    root1 = buildTree();

    cout<<"\nCreate second  binary tree\n";
    node* root2;
    root2 = buildTree();

    if(checkSubtreeOfAnotherTree(root1, root2))
        cout<<"\nYes, first tree is subtree of second tree";
    else
        cout<<"\nNo, first tree is not subtree of second tree";
}
