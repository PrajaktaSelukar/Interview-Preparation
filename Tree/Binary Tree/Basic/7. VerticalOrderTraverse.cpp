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

void findMinMaxHD(node* root, int* min, int* max, int hd)
{
    if(root==NULL)
        return ;

    if(hd < *min)
        *min = hd;
    if(hd > *max)
        *max = hd;

    findMinMaxHD(root->left, min, max, hd-1);
    findMinMaxHD(root->right, min, max, hd+1);
}

void printVerticalLine(node* root, int level, int hd)
{
    if(root == NULL)
        return;

    if(hd == level)
        cout<<root->data<<" ";

    printVerticalLine(root->left, level, hd-1);
    printVerticalLine(root->right, level, hd+1);
}

void printVerticalOrder(node* root)
{
    int min=0, max=0, hd=0;
    findMinMaxHD(root, &min, &max, hd);

    for(int level=min; level<=max; level++)
    {
        printVerticalLine(root, level, 0);
        cout<<"\n";
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Vertical Order Traversal\n";
    printVerticalOrder(root);
}
