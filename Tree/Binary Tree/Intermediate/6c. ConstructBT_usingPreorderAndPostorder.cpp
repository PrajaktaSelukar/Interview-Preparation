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

node* buildTreeHelper(int* pre, int n, int low, int high, unordered_map<int, int> &mp)
{
    static int pIndex = 0;

    node* root = newnode(pre[pIndex++]);
    cout<<"**"<<root->data<<" ";

    if(pIndex == n)
        return root;

    int rootIndex = mp[pre[pIndex]];
    cout<<rootIndex<<"**";

    if(low <= high && rootIndex+1 <= high-1)
    {
        root->left = buildTreeHelper(pre, n, low, rootIndex, mp);
        root->right = buildTreeHelper(pre, n, rootIndex+1, high-1, mp);
    }

    return root;
}

node* buildTree(int* pre, int* post, int n)
{
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
        mp[post[i]]=i;

    return buildTreeHelper(pre, n, 0, n-1, mp);
}

int main()
{
    int n;
    cin>>n;

    cout<<"Enter Preorder traversal : \n";
    int pre[n];
    for(int i=0; i<n; i++)
        cin>>pre[i];

    cout<<"\nEnter Postorder traversal : \n";
    int post[n];
    for(int i=0; i<n; i++)
        cin>>post[i];

    node* root = buildTree(pre, post, n);

    cout<<"\n\nPrint Inorder traversal of tree\n";
    printInorder(root);

    cout<<"\n\nPrint Level Order traversal of tree\n";
    printLevelOrder(root);
}
