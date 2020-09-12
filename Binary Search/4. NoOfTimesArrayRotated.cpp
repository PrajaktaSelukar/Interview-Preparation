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

int NoOfTimesArrayRotated(int arr[], int n)
{
    if(n==1)
        return 0;

    if(arr[0] <= arr[n-1])
        return 0;

    int start=0;
    int end=n-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        int prev = (mid + n-1)%n;
        int next = (mid + 1)%n;

        if(arr[prev] >= arr[mid] && arr[mid] <= arr[next])
            return mid;

        else if(arr[start] <= arr[mid])
            start = mid+1;

        else if(arr[mid] <= arr[end])
            end = mid-1;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<NoOfTimesArrayRotated(arr, n)<<endl;
}

