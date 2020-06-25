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

int findMin(node* root)
{
    if(root == NULL)
        return INT_MAX;

    //Return minimum of three values
    //1. root's value  2. min of left subtree  3. min of right subtree
    int ans=root->data;

    int lans = findMin(root->left);
    int rans = findMin(root->right);

    return min(ans, min(lans, rans));
}

int findMax(node* root)
{
    if(root == NULL)
        return INT_MIN;

    //Return maximum of three values
    //1. root's value  2. max of left subtree  3. max of right subtree
    int ans=root->data;

    int lans = findMax(root->left);
    int rans = findMax(root->right);

    return max(ans, max(lans, rans));
}

int findHeight(node* root)
{
    if(root == NULL)
        return 0;

    int lheight = findHeight(root->left);
    int rheight = findHeight(root->right);

    return 1 + max(lheight, rheight);
}

int countLeafNodes(node* root)
{
    if(root == NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;

    int lans = countLeafNodes(root->left);
    int rans = countLeafNodes(root->right);

    return lans+rans;
}

bool ifKeyExists(node* root, int key)
{
    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    else
    {
        int res1 = ifKeyExists(root->left, key);

        if(res1)
            return true;

        int res2 = ifKeyExists(root->right, key);
        return res2;
    }
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

void printInorder(struct node*node)
{
    if(node==NULL)
        return;

    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

void printPreorder(struct node*node)
{
    if(node==NULL)
        return;

    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct node*node)
{
    if(node==NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nTraverse the tree : ";
    cout<<"\nPrint PreOrder\n";
    printPreorder(root);

    cout<<"\nPrint PostOrder\n";
    printPostorder(root);

    cout<<"\nInorder Traversal \n";
    printInorder(root);

    cout<<"\n\nPrint Level Order\n";
    printLevelOrder(root);

    cout<<"\n\nMaximum element : "<<findMax(root);

    cout<<"\n\nMinimum element : "<<findMin(root);

    cout<<"\n\nHeight of Binary Tree : "<< findHeight(root);

    cout<<"\n\nCount Leaf Nodes of Binary Tree : "<<countLeafNodes(root);

    cout<<"\n\nEnter a key to search : ";
    int key;
    cin>>key;
    if(ifKeyExists(root, key))
        cout<<"Yes, it exists";
    else
        cout<<"No, does not exist";
}
