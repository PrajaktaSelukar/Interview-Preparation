#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printDuplicates(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        arr[ arr[i] % n] = arr[ arr[i] % n] + n;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] >= n*2)
            cout<<i<<" ";
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    printDuplicates(arr, n);
}
