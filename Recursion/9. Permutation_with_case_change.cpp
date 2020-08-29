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

    string op_lowercase = op;
    string op_uppercase = op;

    op_lowercase.push_back(ip[0]);
    op_uppercase.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);

    print_subsets(ip, op_lowercase);
    print_subsets(ip, op_uppercase);
}

int main()
{
    string ip;
    cin>>ip;

    string op="";

    print_subsets(ip, op);
}
