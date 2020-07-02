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

int height(node* root)
{
    if(root == NULL)
        return 0;

    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        return 1 + max(lheight, rheight);
    }
}

void printGivenLevel(node* root, int level, bool dir)
{
    if(root == NULL)
        return;

    if(level == 1)
        cout<<root->data<<" ";

    else
    {
        if(dir == false)  // going left
        {
            printGivenLevel(root->right, level-1, dir);
            printGivenLevel(root->left, level-1, dir);

        }
        else if(dir == true)  //going right
        {
            printGivenLevel(root->left, level-1, dir);
            printGivenLevel(root->right, level-1, dir);
        }
    }
}

void printSpiralOrder(node* root)
{
    int h = height(root);

    bool dir = false;
    for(int level=1; level<=h; level++)
    {
        printGivenLevel(root, level, dir);
        dir = !dir;      // Reverse direction
        cout<<"\n";
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nPrint Spiral Order Traverse\n";
    printSpiralOrder(root);
}
