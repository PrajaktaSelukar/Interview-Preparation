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

void printRightView(node* root)
{
    if(root == NULL)
        return;

    queue<node* > q;
    q.push(root);

    while(!q.empty())
    {
        //no of nodes at current level
        int n = q.size();

        //traverse all nodes at current level
        for(int i=1; i<=n; i++)
        {
            node* temp = q.front();
            q.pop();

            if(i == n)
                cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Right Side View of Binary Tree\n";
    printRightView(root);
}
