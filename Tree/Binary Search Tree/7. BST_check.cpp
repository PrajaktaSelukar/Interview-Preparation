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

void LevelOrderTraverse(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(q.empty())
        {
            cout<<endl;
            return;
        }
        else if(temp == NULL)
        {
            q.push(NULL);
            cout<<endl;
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

bool checkBST_helper(node* root, int min, int max)
{
    if(root == NULL)
        return true;

    if(root->data < min || root->data > max)
        return false;

    return checkBST_helper(root->left, min, root->data-1) && checkBST_helper(root->right, root->data+1, max);
}

bool checkBST(node* root)
{
    int min=INT_MIN, max=INT_MAX;

    checkBST_helper(root, min, max);
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Level Order\n";
    LevelOrderTraverse(root);

    if(checkBST(root))
        cout<<"\nYes, it is a BST\n";
    else
        cout<<"\nNo, it is not a BST\n";
}
