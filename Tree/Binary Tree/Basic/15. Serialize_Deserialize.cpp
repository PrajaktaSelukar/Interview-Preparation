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

void serialize(node* root, FILE* fp)
{
    if(root == NULL)
    {
        fprintf(fp, "%d ", -1);
        return;
    }

    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deSerialize(node* &root, FILE* fp)
{
    int val;

    if(!fscanf(fp, "%d ", &val))
        return;

    if(val == -1)
        return;

    root = newnode(val);

    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

int main()
{
    node* root;
    root = buildTree();

    FILE* fp = fopen("15tree.txt", "w");
    if(fp == NULL)
    {
        puts("Could no open the file\n");
        return 0;
    }

    serialize(root, fp);
    fclose(fp);

    node* root1 = NULL;
    fp = fopen("15tree.txt", "r");

    deSerialize(root1, fp);

    cout<<"Level order traversal \n";
    printLevelOrder(root1);
}
