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

string inorder(node* root, unordered_map<string, int> &mp)
{
    if(root == NULL)
        return "";

    string str = "(";
    str += inorder(root->left, mp);
    str += to_string(root->data);
    str += inorder(root->right, mp);
    str += ")";

    if(mp[str] == 1) //already one subtree is present
        cout<<root->data<<" ";

    mp[str]++;

    return str;
}

void printAllDupSub(node* root)
{
    unordered_map<string, int> mp;
    inorder(root, mp);
}

int main()
{
    node* root;
    root = buildTree();

    printAllDupSub(root);
}
