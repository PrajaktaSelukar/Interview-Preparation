#include<iostream>
#include<stack>
using namespace std;

void insert_at_right_pos(stack<int> &stk, int tmp)
{
    if(stk.size()==0 || stk.top() <= tmp)
    {
        stk.push(tmp);
        return;
    }

    int val = stk.top();
    stk.pop();
    insert_at_right_pos(stk, tmp);
    stk.push(val);
    return;
}

void sort_stack(stack<int> &stk)
{
    if(stk.size()==1)
    {
        return;
    }

    int tmp = stk.top();
    stk.pop();
    sort_stack(stk);
    insert_at_right_pos(stk, tmp);
    return;
}

int main()
{
    stack<int> stk;
    int n;
    cin>>n;
    int tmp;
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        stk.push(tmp);
    }

    sort_stack(stk);

    while(!stk.empty())
    {
        tmp=stk.top();
        stk.pop();
        cout<<tmp<<" ";
    }
}
