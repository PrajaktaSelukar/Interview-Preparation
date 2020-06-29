#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newnode(int key)
{
    node* temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int key)
{
    if(root == NULL)
    {
        return newnode(key);
    }

    if(key < root->data)
        root->left = insert(root->left, key);

    if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

node* getInorderSuccessor(node* root)
{
    if(root == NULL || root->left == NULL)
        return NULL;

    node* temp = root->right;
    while(temp->left)
    {
        temp = temp->left;
    }

    return temp;
}

node* getInorderPredecessor(node* root)
{
    if(root == NULL || root->left == NULL)
        return NULL;

    node* temp = root->left;
    while(temp->right)
    {
        temp = temp->right;
    }

    return temp;
}

node* deletion(node* root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deletion(root->left, key);

    else if(key > root->data)
        root->right = deletion(root->right, key);

    else // key==root->data
    {
        //No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //one child
        if(root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        //Two children
        node* toBeDeleted = getInorderPredecessor(root);
        root->data = toBeDeleted->data;
        root->left = deletion(root->left, toBeDeleted->data);

        /*
        node* toBeDeleted = getInorderSuccessor(root);
        root->data = toBeDeleted->data;
        root->right = deletion(root->right, toBeDeleted->data);
        */
        return root;

    }
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

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;

    int n;
    cout<<"Enter no of nodes to be entered(n) : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        root = insert(root, arr[i]);
    }

    cout<<"\n\nPrint Inorder traverse\n";
    inorder(root);

    cout<<"\n\nPrint Level Order Traversal\n";
    LevelOrderTraverse(root);
}
