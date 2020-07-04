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

void helper(node* root, int sum, vector<int> &vec, int sum_so_far)
{
    if(root == NULL)
        return;

    sum_so_far += root->data;
    vec.push_back(root->data);

    if(sum_so_far == sum)
    {
        for(int j=0; j<vec.size(); j++)
            cout<<vec[j]<<" ";

        cout<<"\n";
    }

    if(root->left)
        helper(root->left, sum, vec, sum_so_far);

    if(root->right)
        helper(root->right, sum, vec, sum_so_far);

    vec.pop_back();
}

void print_k_sumPath(node* root, int sum)
{
    vector<int> vec;
    helper(root, sum, vec, 0);
}

int main()
{
    node* root;
    root = buildTree();
    printLevelOrder(root);

    cout<<"\nEnter a number : ";
    int sum;
    cin>>sum;

    print_k_sumPath(root, sum);
}
