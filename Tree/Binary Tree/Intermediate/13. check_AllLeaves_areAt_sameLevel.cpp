#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

node* newnode(int key)
{
    node* temp = new struct node;
    temp->data =key;
    temp->left =NULL;
    temp->right = NULL;

    return temp;
}

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

bool traverse(node* root, int level, int* leafLevel)
{
    if(root == NULL)
        return true;

    //if the node is a leaf
    if(root->left == NULL && root->right == NULL)
    {
        if(*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }

        //if this is not first time
        if(*leafLevel == level)
            return true;
        else
            return false;
    }
    //if node is not a leaf
    return traverse(root->left, level+1, leafLevel) && traverse(root->right, level+1, leafLevel);
}

bool check(node* root)
{
    int level = 0;
    int leafLevel = 0;
    return traverse(root, level, &leafLevel);
}

int main()
{
    node* root;
    root = buildTree();

    if(check(root))
        cout<<"\nYes leaves are at same level";
    else
        cout<<"\nNo leaves are not at same level";
}
