#include<iostream>
#include<string>
using namespace std;

void permutation_with_spaces(string inp, string op)
{
    if(inp=="")
    {
        cout<<op<<endl;
        return;
    }

    string op_with_space=op;
    string op_without_space=op;

    op_with_space.push_back(' ');
    op_with_space.push_back(inp[0]);
    op_without_space.push_back(inp[0]);

    inp.erase(inp.begin()+0);

    permutation_with_spaces(inp, op_with_space);
    permutation_with_spaces(inp, op_without_space);
}

int main()
{
    string inp;
    cin>>inp;
    string op="";

    op.push_back(inp[0]);
    inp.erase(inp.begin()+0);

    permutation_with_spaces(inp, op);
}
