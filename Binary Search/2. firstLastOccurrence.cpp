#include<iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int ele)
{
    int start=0;
    int end=n-1;
    int first=-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(ele == arr[mid])
        {
            first=mid;
            end=mid-1;
        }

        else if(ele < arr[mid])
            end = mid-1;

        else
            start = mid+1;
    }
    return first;
}

int lastOccurrence(int arr[], int n, int ele)
{
    int start=0;
    int end=n-1;
    int last=-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(ele == arr[mid])
        {
            last=mid;
            start=mid+1;
        }

        else if(ele < arr[mid])
            end = mid-1;

        else
            start = mid+1;
    }
    return last;
}

int main()
{
    int n, ele;
    cin>>n>>ele;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<firstOccurrence(arr, n, ele)<<endl;
    cout<<lastOccurrence(arr, n, ele)<<endl;
}
