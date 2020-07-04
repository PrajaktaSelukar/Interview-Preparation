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

void helper(node* root, int sum, vector<int> &vec)
{
    if(root == NULL)
        return;

    vec.push_back(root->data);

    helper(root->left, sum, vec);

    helper(root->right, sum, vec);

    int sum_so_far=0;
    for(int i=vec.size()-1; i>=0; i--)
    {
        sum_so_far += vec[i];

        if(sum_so_far == sum)
        {
            for(int j=i; j<vec.size(); j++)
                cout<<vec[j]<<" ";

            cout<<"\n";
        }
    }

    vec.pop_back();
}

void print_k_sumPath(node* root, int sum)
{
    vector<int> vec;
    helper(root, sum, vec);
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
