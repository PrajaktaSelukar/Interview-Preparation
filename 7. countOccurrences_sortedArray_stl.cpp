#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countOccurrences(int arr[], int n, int k)
{
    int *low = lower_bound(arr, arr+n, k);

    if(low==(arr+n) || *low != k)
        return 0;

    int *high = upper_bound(arr, arr+n, k);

    return high-low;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    cout<<countOccurrences(arr, n, k);
}
