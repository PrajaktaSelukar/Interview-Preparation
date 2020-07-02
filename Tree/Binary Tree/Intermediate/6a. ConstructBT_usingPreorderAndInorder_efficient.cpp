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

node* buildTreeHelper(int* pre, int start, int end, unordered_map<int, int> &mp)
{
    if(start > end)
        return NULL;

    static int preIndex = 0;

    node* root = newnode(pre[preIndex++]);

    int rootIndex = mp[root->data];

    root->left = buildTreeHelper(pre, start, rootIndex-1, mp);
    root->right = buildTreeHelper(pre, rootIndex+1, end, mp);

    return root;
}

node* buildTree(int* in, int* pre, int size)
{
    unordered_map<int, int> mp;

    for(int i=0; i<size; i++)
        mp[in[i]]=i;

    return buildTreeHelper(pre, 0, size-1, mp);
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
