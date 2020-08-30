#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_subsets(string ip, string op, vector<string> &res)
{
    if(ip.length() == 0)
    {
        res.push_back(op);
        return;
    }

    if(isalpha(ip[0]))
    {
        string op_lowercase = op;
        string op_uppercase = op;

        op_lowercase.push_back(tolower(ip[0]));
        op_uppercase.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);

        print_subsets(ip, op_lowercase, res);
        print_subsets(ip, op_uppercase, res);
    }
    else
    {
        string op_with_digit = op;

        op_with_digit.push_back(ip[0]);
        ip.erase(ip.begin() + 0);

        print_subsets(ip, op_with_digit, res);
    }
}

vector<string> solve(string s)
{
    string ip = s;
    string op="";

    vector<string> res;
    print_subsets(ip, op, res);
    return res;
}

int main()
{
    string s;
    cin>>s;

    vector<string> res;
    res = solve(s);

    vector<string> :: iterator itr;
    for(itr=res.begin(); itr!=res.end(); itr++)
        cout<<*itr<<endl;
}
