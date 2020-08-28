#include<iostream>
#include<bits/stdc++.h>
using namespace std;

set<string> res;

void print_unique_subsets(string ip, string op)
{
    if(ip.length() == 0)
    {
        res.insert(op);
        return;
    }

    string op_with_curr = op;
    string op_without_curr = op;

    op_with_curr.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    print_unique_subsets(ip, op_without_curr);
    print_unique_subsets(ip, op_with_curr);
}

int main()
{
    string ip;
    cin>>ip;

    string op="";

    print_unique_subsets(ip, op);

    set<string> :: iterator itr;

    for(itr = res.begin(); itr != res.end(); itr++)
    {
        cout<<*itr<<endl;
    }
}
