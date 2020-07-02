#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

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

void traverse(node* root, int dist, map<int, vector<int> > &mp)
{
    if(root == NULL)
        return;

    mp[dist].push_back(root->data);

    traverse(root->left, dist+1, mp);

    traverse(root->right, dist, mp);
}

void printDiagonalElements(node* root)
{
    int dist=0;
    map<int, vector<int> > mp;
    traverse(root, dist, mp);

    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    {
        for(auto it=itr->second.begin(); it != itr->second.end(); it++)
            cout<<*it<<" ";

        cout<<endl;
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Diagonal Traversal in Binary Tree\n";
    printDiagonalElements(root);
}
