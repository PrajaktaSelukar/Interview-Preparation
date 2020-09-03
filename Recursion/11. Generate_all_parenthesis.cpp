#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generate_all_parenthesis(int open, int close, string op, vector<string> &res)
{
    if(open == 0 && close == 0)
    {
        res.push_back(op);
        return;
    }

    if(open != 0)
    {
        string op_with_open = op;
        op_with_open.push_back('(');
        generate_all_parenthesis(open-1, close, op_with_open, res);
    }

    if(open < close)
    {
        string op_with_close = op;
        op_with_close.push_back(')');
        generate_all_parenthesis(open, close-1, op_with_close, res);
    }
}

int main()
{
    int n;
    cin>>n;

    string op="(";
    int open=n-1;
    int close = n;

    vector<string> res;
    generate_all_parenthesis(open, close, op, res);

    vector<string> :: iterator itr;
    for(itr=res.begin(); itr!=res.end(); itr++)
        cout<<*itr<<endl;
}
