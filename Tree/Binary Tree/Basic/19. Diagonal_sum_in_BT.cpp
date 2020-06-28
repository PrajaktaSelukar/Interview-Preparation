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

void printDiagonalSumIterative(node* root)
{
    if(root == NULL)
        return;

    queue<node*> q;
    q.push(root);  // push root
    q.push(NULL);  // push delimiter

    int sum=0, cnt=0;
    while(!q.empty())
    {
        node* curr = q.front();
        q.pop();

        //if current is delimiter then insert another for next diagonal
        // and cout nextline
        if(curr == NULL)
        {
            if(q.empty())
                return;
            cout<<"Diagonal "<<cnt++<<" : "<<sum;
            sum=0;
            cout<<endl;
            q.push(NULL);
        }
        else
        {

            while(curr)
            {
                sum += curr->data;

                if(curr->left)
                    q.push(curr->left);

                curr= curr->right;
            }

        }
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Diagonal Sum in Binary Tree : \n";
    printDiagonalSumIterative(root);
}
