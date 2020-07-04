#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

node* newnode(int key)
{
    node* temp = new struct node;
    temp->data =key;
    temp->left =NULL;
    temp->right = NULL;

    return temp;
}

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

void printLevelOrder(node* root)
{
    queue<node*> q;

q.push(root);
q.push(NULL);

while(!q.empty()){


    struct node* n = q.front();
    q.pop();
    if(q.empty()){
    cout<<endl;
    break;
    }

    if(n==NULL && !q.empty())
    {
        q.push(NULL);
        cout<<endl;
    }

    else{
    cout<<n->data<<" ";
    if(n->left!=NULL)
        q.push(n->left);
    if(n->right!=NULL)
        q.push(n->right);
        }
    }
}

void longestSumRootToLeafHelper(node* root, int sum, int level, int* maxSum, int* maxLen)
{
    if(root == NULL)  // reached till leaf
    {
        if(*maxLen < level)
        {
            *maxLen=level;
            *maxSum=sum;
        }
        else if(*maxLen == level && *maxSum<sum)
            *maxSum=sum;

        return;
    }

    longestSumRootToLeafHelper(root->left, sum + root->data, level + 1, maxSum, maxLen);
    longestSumRootToLeafHelper(root->right, sum + root->data, level + 1, maxSum, maxLen);
}

int longestSumRootToLeaf(node* root)
{
    if(root == NULL)
        return 0;

    int sum=0;
    int level=0;
    int maxSum=INT_MIN;
    int maxLen=0;

    longestSumRootToLeafHelper(root, sum, level, &maxSum, &maxLen);
    return maxSum;
}

int main()
{
    node* root;
    root = buildTree();
    printLevelOrder(root);

    cout<<"\n\nSum of Longest Root To Leaf Path : "<<longestSumRootToLeaf(root);
}
