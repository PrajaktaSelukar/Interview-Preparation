#include<iostream>
using namespace std;

int binarysearch(int arr[], int n, int ele)
{
    int start=0;
    int end=n-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(ele == arr[mid])
            return mid;

        else if(ele > arr[mid])
            end = mid-1;

        else
            start = mid+1;
    }
    return -1;
}

int main()
{
    int n, ele;
    cin>>n>>ele;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<binarysearch(arr, n, ele)<<endl;
}
