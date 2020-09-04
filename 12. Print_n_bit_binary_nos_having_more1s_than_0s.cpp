#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generate_all_parenthesis(string op, int ones, int zeroes, int n, vector<string> &res)
{
    if(n == 0)
    {
        res.push_back(op);
        return;
    }

    string op_with_ones = op;
    op_with_ones.push_back('1');
    generate_all_parenthesis(op_with_ones, ones+1, zeroes, n-1, res);

    if(ones > zeroes)
    {
        string op_with_zeroes = op;
        op_with_zeroes.push_back('0');
        generate_all_parenthesis(op_with_zeroes, ones, zeroes+1, n-1, res);
    }
}

int main()
{
    int n;
    cin>>n;

    string op="";
    int ones=0;
    int zeroes=0;

    vector<string> res;
    generate_all_parenthesis(op, ones, zeroes, n, res);

    vector<string> :: iterator itr;
    for(itr=res.begin(); itr!=res.end(); itr++)
        cout<<*itr<<endl;
}
