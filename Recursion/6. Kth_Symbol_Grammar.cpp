#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    if(n==1 && k==1)
        return 0;

    int len = pow(2, n-1);
    int mid= len/2;

    if(k <= mid)
        return solve(n-1, k);
    else
        return !solve(n-1, k-mid);
}

int main()
{
    int n, k;
    cin>>n>>k;

    cout<<"Kth symbol grammar is : "<<solve(n, k)<<endl;
}
