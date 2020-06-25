#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node** children;
    int childcount;
};

node* buildTree()
{
    node* root = new node;
    cout<<"Enter Root's data : ";
    cin>>root->data;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter child count of node with data as "<<temp->data<<" : ";
        cin>>temp->childcount;
        temp->children = new node*[temp->childcount];

        for(int i=0; i<temp->childcount; i++)
        {
            temp->children[i] = new node;
            cout<<"Enter data for child "<<i<<" : ";
            cin>>temp->children[i]->data;
            q.push(temp->children[i]);
        }
    }
    return root;
}

void buildRecursively(struct node** root)
{
    *root = new node;
    cout<<"Enter Node's data : ";
    cin>>(*root)->data;

    cout<<"Enter child count of node with data as "<<(*root)->data<<" : ";
    cin>> (*root)->childcount;

    if((*root)->childcount == 0)
        return;

    (*root)->children = new node*[(*root)->childcount];

    for(int i=0; i<(*root)->childcount; i++)
    {
        (*root)->children[i] = NULL;
        buildRecursively(&(*root)->children[i]);
    }
}

void printPreOrder(node* temp)
{
    if(temp == NULL)
        return;

    cout<<temp->data<<" ";
    for(int i=0; i<temp->childcount; i++)
        printPreOrder(temp->children[i]);
}

void printPostOrder(node* temp)
{
    if(temp == NULL)
        return;

    for(int i=0; i<temp->childcount; i++)
        printPostOrder(temp->children[i]);

    cout<<temp->data<<" ";
}

void printLevelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(q.empty())
        {
            cout<<"\n";
            break;
        }
        else if(temp == NULL)
        {
            q.push(NULL);
            cout<<"\n";
        }
        else
        {
            cout<<temp->data<<" ";
            for(int i=0; i<temp->childcount; i++)
                q.push(temp->children[i]);
        }
    }
}

node* findMax(node* root)
{
    if(root == NULL)
        return root;

    node* largest=root;
    for(int i=0; i<root->childcount; i++)
    {
        node* temp=findMax(root->children[i]);
        if(temp->data > largest->data)
            largest=temp;
    }
    return largest;
}

node* findMin(node* root)
{
    if(root == NULL)
        return root;

    node* smallest=root;
    for(int i=0; i<root->childcount; i++)
    {
        node* temp=findMin(root->children[i]);
        if(temp->data < smallest->data)
            smallest=temp;
    }
    return smallest;
}

int findDepth(node* root)
{
    if(root == NULL)
        return 0;

    int depth=-1;
    for(int i=0; i<root->childcount; i++)
        depth = max(depth, findDepth(root->children[i]));

    return 1 + depth;
}

int main()
{
    cout<<"Build a tree -\n1. Iteratively\n2. Recursively \nOption : ";
    int option;
    cin>>option;
    node* root;

    switch(option)
    {
        case 1:
            root = buildTree();
            break;
        case 2:
            buildRecursively(&root);
            break;
    }

    cout<<"\nTraverse the tree ";
    cout<<"\nPrint PreOrder\n";
    printPreOrder(root);

    cout<<"\nPrint PostOrder\n";
    printPostOrder(root);

    cout<<"\nPrint Level Order\n";
    printLevelOrder(root);

    node* maxm = findMax(root);
    cout<<"\n\nMaximum element : "<<maxm->data;

    node* minm = findMin(root);
    cout<<"\n\nMinimum element : "<<minm->data;

    cout<<"\n\nDepth of Tree : "<< findDepth(root);

}
