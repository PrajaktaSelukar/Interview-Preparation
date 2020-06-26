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

void getVerticalOrder(node* root, int hd, map<int , vector<int> > &mp)
{
    if(root == NULL)
        return;

    mp[hd].push_back(root->data);

    getVerticalOrder(root->left, hd-1, mp);
    getVerticalOrder(root->right, hd+1, mp);
}

void printVerticalOrder(node* root)
{
   map<int , vector<int> > mp;
   int hd=0;
   getVerticalOrder(root, hd, mp);

    map<int , vector<int> > ::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<"\n";
    }

}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Vertical Order Traversal\n";
    printVerticalOrder(root);
}
