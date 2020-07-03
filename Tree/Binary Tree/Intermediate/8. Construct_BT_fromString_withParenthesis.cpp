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

void printPreorder(struct node*node)
{
    if(node==NULL)
        return;

    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int findIndex(string str, int start, int end)
{
    if(start > end)
        return -1;

    stack<char> s;

    for(int i=start; i<=end; i++)
    {
        if(str[i] == '(')
            s.push(str[i]);

        else if(str[i] == ')')
        {
            if(s.top() == '(')
            {
                s.pop();

                if(s.empty())
                    return i;
            }
        }
    }

    return -1;
}

node* stringToBT(string str, int start, int end)
{
    if(start > end)
        return NULL;

    node* root = newnode(str[start] - '0'); //convert into integer

    int index=-1;

    //if next char is '(' then find the index of its complement ')'
    if(start+1 <= end && str[start+1]=='(')
        index=findIndex(str, start+1, end);

    if(index != -1) // if index is found
    {
        root->left = stringToBT(str, start+2, index-1);
        root->right = stringToBT(str, index+2, end-1);
    }
    return root;
}

int main()
{
    string str;
    cin>>str;
    int n=str.length();

    node* root = stringToBT(str, 0, n-1);

    printPreorder(root);
}
