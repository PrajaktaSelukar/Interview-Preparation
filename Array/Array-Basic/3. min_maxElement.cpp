#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int* min_maxElement(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    for(int i=1; i<n; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
        else if(max < arr[i])
        {
            max = arr[i];
        }
    }

    cout<<"\nMinimum element : "<<min;
    cout<<"\nMaximum element : "<<max;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    min_maxElement(arr, n);
}
