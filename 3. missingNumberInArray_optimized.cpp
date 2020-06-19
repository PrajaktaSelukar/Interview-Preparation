#include<iostream>
using namespace std;

int missingNumberInArray(int arr[], int n)
{
    int x=arr[0], y=1;

    for(int i=1; i<n; i++)
    {
        x = x ^ arr[i];
    }

    for(int i=2; i<=n+1; i++)
    {
        y = y ^ i;
    }

    return x^y;

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\n";
    cout<<missingNumberInArray(arr, n);

}
