#include<bits/stdc++.h>
using namespace std;

int findRange(int arr[], int n)
{
    int min=*min_element(arr, arr+n);
    int max=*max_element(arr, arr+n);

    return max-min;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<findRange(arr, n);
}
