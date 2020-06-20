#include<iostream>
using namespace std;

int multiply(int x, int res[], int n)
{
    int carry = 0;

    for(int i=0; i<n; i++)
    {
        int prod = res[i]*x + carry;

        res[i]= prod%10;

        carry = prod/10;
    }

    while(carry)
    {
        res[n] = carry%10;
        carry = carry/10;
        n++;
    }
    return n;
}

void factorial(int no)
{
    int res[500];
    res[0]=1;
    int res_size = 1;

    for(int i=2; i<=no ; i++)
        res_size = multiply(i, res, res_size);

    cout<<"\nFactorial of "<<no<<" : \n";
    for(int i=res_size-1; i>=0; i--)
        cout<<res[i];
}

int main()
{
    int n;
    cin>>n;

    factorial(n);
}
