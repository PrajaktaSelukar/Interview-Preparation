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

void nthInorder(node* root, int key)
{
    if(root==NULL)
        return;
    static int i=0;

    nthInorder(root->left, key);

    i++;
    if(i == key)
        cout<<root->data;

    nthInorder(root->right, key);
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"Enter to find nth node of Inorder Traversal\n";
    int key;
    cin>>key;

    nthInorder(root, key);
}
