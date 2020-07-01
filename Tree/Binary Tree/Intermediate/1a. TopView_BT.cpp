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

void printTopView(node* root)
{
    if(root == NULL)
        return;

    node* temp = NULL;
    queue<pair<node*, int> > q;
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty())
    {
        temp = q.front().first;
        int vd = q.front().second;
        q.pop();

        //if any node is not found at hat vertical dist
        //just insert that node and print it
        if(mp.find(vd) == mp.end())
        {
            cout<<temp->data<<" ";
            mp[vd] = temp->data;
        }

        if(temp->left)
            q.push({temp->left, vd-1});

        if(temp->right)
            q.push({temp->right, vd+1});
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Top View of Binary Tree\n";
    printTopView(root);
}
