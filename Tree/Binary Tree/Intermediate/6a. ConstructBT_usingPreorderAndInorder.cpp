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

void printInorder(struct node*node)
{
    if(node==NULL)
        return;

    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
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

    if(n==NULL&&!q.empty()){
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

node* buildTreeHelper(int* in, int inS, int inE, int* pre, int preS, int preE)
{
    if(inS > inE)  //or if(preS > preE)
        return NULL;

    int rootData = pre[preS];

    //Find the index of root in inorder
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++)
    {
        if(in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // Find the parameters
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;

    int rInS = rootIndex+1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    node* root = newnode(rootData);

    root->left = buildTreeHelper(in, lInS, lInE, pre, lPreS, lPreE);
    root->right = buildTreeHelper(in, rInS, rInE, pre, rPreS, rPreE);

    return root;
}

node* buildTree(int* in, int* pre, int size)
{
    return buildTreeHelper(in, 0, size-1, pre, 0, size-1);
}

int main()
{
    int n;
    cin>>n;

    cout<<"Enter inorder traversal : \n";
    int in[n];
    for(int i=0; i<n; i++)
        cin>>in[i];

    cout<<"\nEnter preorder traversal : \n";
    int pre[n];
    for(int i=0; i<n; i++)
        cin>>pre[i];

    node* root = buildTree(in, pre, n);

    cout<<"\n\nPrint Inorder traversal of tree\n";
    printInorder(root);

    cout<<"\n\nPrint Level Order traversal of tree\n";
    printLevelOrder(root);
}
