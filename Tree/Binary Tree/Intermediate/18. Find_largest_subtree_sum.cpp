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

int helper(node* root, int &ans)
{
    if(root == NULL)
        return 0;

    int curr_sum = root->data + helper(root->left, ans) + helper(root->right, ans);

    if(ans < curr_sum)
        ans=curr_sum;

    return curr_sum;
}

int largestSubtreeSum(node* root)
{
    if(root == NULL)
        return 0;

    int ans=INT_MIN;

    helper(root, ans);
    return ans;
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nLargest Subtree Sum in Binary Tree : "<<largestSubtreeSum(root);
}
