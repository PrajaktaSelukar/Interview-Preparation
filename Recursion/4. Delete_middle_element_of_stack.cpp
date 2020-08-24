#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &stk, int middle_ele_pos)
{
    if(middle_ele_pos == 1)
    {
        stk.pop();
        return;
    }

    int tmp = stk.top();
    stk.pop();

    solve(stk, middle_ele_pos - 1);
    stk.push(tmp);
    return;
}

void delete_middle_element_of_stack(stack<int> &stk)
{
    if(stk.size()==0)
    {
        return;
    }

    int middle_ele_pos;
    if(middle_ele_pos % 2 != 0)
        middle_ele_pos = stk.size()/2;
    else
        middle_ele_pos = (stk.size()/2)+1;

    solve(stk, middle_ele_pos);
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

    delete_middle_element_of_stack(stk);

    while(!stk.empty())
    {
        tmp=stk.top();
        stk.pop();
        cout<<tmp<<" ";
    }
}

