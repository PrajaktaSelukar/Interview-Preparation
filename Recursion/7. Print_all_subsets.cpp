#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_subsets(string ip, string op)
{
    if(ip.length() == 0)
    {
        cout<<op<<endl;
        return;
    }

    string op_with_curr = op;
    string op_without_curr = op;

    op_with_curr.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    print_subsets(ip, op_without_curr);
    print_subsets(ip, op_with_curr);
}

int main()
{
    string ip;
    cin>>ip;

    string op="";

    print_subsets(ip, op);
}
