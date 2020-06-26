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

void printSpiralOrder(node* root)
{
    stack<node*> s1;  //going right to left
    stack<node*> s2; // going left to right
    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node* temp = s1.top();
            cout<<temp->data<<" ";
            s1.pop();

            //push nodes of next level to s2
            if(temp->right)   //Enqueue right child
                s2.push(temp->right);

            if(temp->left)    //Enqueue left child
                s2.push(temp->left);
        }

        while(!s2.empty())
        {
            node* temp = s2.top();
            cout<<temp->data<<" ";
            s2.pop();

            //push nodes of next level to s2
            if(temp->left)    //Enqueue left child
                s1.push(temp->left);

            if(temp->right)   //Enqueue right child
                s1.push(temp->right);
        }
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Spiral Order\n";
    printSpiralOrder(root);
}
