#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newnode(int key)
{
    node* temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int key)
{
    if(root == NULL)
    {
        return newnode(key);
    }

    if(key < root->data)
        root->left = insert(root->left, key);

    if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void LevelOrderTraverse(node* root)
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
            cout<<endl;
            return;
        }
        else if(temp == NULL)
        {
            q.push(NULL);
            cout<<endl;
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

bool findTarget_helper(node* root, int k, unordered_set<int> &st)
    {
        if(root == NULL)
            return false;

        if(findTarget_helper(root->left, k, st))
            return true;

        if(st.find(k - root->data) != st.end())
            return true;

        else
            st.insert(root->data);

        return findTarget_helper(root->right, k, st);

    }

    bool findTarget(node* root, int k) {
        unordered_set<int> st;
        return findTarget_helper(root, k, st);
    }

    int main()
{
    node* root = NULL;

    int n;
    cout<<"Enter no of nodes to be entered(n) : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        root = insert(root, arr[i]);
    }

    cout<<"\n\n";
    LevelOrderTraverse(root);

    cout<<"\nEnter k : ";
    int k;
    cin>>k;

    if(findTarget(root, k))
        cout<<"\nPair Exists\n";
    else
        cout<<"\nPair does not exists\n";
}
