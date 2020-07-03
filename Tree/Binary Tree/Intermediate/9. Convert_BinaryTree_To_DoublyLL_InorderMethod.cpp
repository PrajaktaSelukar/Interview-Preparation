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

void BinaryTree_To_DoublyLL(node* root, node** head)
{
    if(root == NULL) //check tree is empty or not
        return;

    static node* prev = NULL;

    BinaryTree_To_DoublyLL(root->left, head);

    if(prev == NULL)
        *head=root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev=root;

    BinaryTree_To_DoublyLL(root->right, head);
}

void printList(node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main()
{
    node* root;
    root = buildTree();

    cout<<"\nConvert Binary Tree To Doubly Linked List\n";
    node* head = NULL;
    BinaryTree_To_DoublyLL(root, &head);

    printList(head);
}
