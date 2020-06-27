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

bool rootToLeafPathSum(node* root, int sum)
{
    if(root == NULL)
    {
        if(sum==0)
            return true;
        return false;
    }
    else
    {
        bool ans=0;
        int subSum = sum-(root->data);

        //if at leaf node sum becomes 0
        if(subSum == 0 && root->left==NULL && root->right==NULL)
            return true;

        if(root->left)
            ans = ans || rootToLeafPathSum(root->left, subSum);

        if(root->right)
            ans = ans || rootToLeafPathSum(root->right, subSum);

        return ans;
    }
}

int main()
{
    node* root;
    root = buildTree();
    printLevelOrder(root);

    cout<<"\nEnter a number : ";
    int sum;
    cin>>sum;

    if(rootToLeafPathSum(root, sum))
        cout<<"\nYes, Root to Leaf path sum is equal to the given number\n";
    else
        cout<<"\nNo, Root to Leaf path sum is not equal to the given number\n";
}
