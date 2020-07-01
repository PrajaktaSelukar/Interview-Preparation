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

void printBottomViewUntil(node* root, int dist, int level, map<int, pair<int, int> > &mp)
{
    if(root == NULL)
        return;

    //if current level is >= maximum level seen so far
    //for the same horizontal distance for first time, update map
    if(level >= mp[dist].second)
    {
        mp[dist] = {root->data, level};
    }

    printBottomViewUntil(root->left, dist-1, level+1, mp);

    printBottomViewUntil(root->right, dist+1, level+1, mp);
}

void printBottomView(node* root)
{
    //key   = horizontal dist of node from root
    //value = pair containing node's value and its level
    map<int, pair<int, int> > mp;
    int dist=0, level=0;

    printBottomViewUntil(root, dist, level, mp);

    for(auto itr : mp)
    {
        cout<<itr.second.first<<" ";
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Bottom View of Binary Tree\n";
    printBottomView(root);
}
