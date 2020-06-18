#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k)
{
    int low=0;
    int high=n-1;
    int mid;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(arr[mid]==k)
            return mid;

        else if(k < arr[mid])
            high = mid-1;

        else if(k > arr[mid])
            low = mid+1;
    }
    return -1;
}

int countOccurrences(int arr[], int n, int k)
{
    int index = binarySearch(arr, n, k);

    if(index == -1)
        return 0;

    int count=1;
    int left = index-1;

    while(left>=0 && arr[left]==arr[index])
    {
        count++;
        left--;
    }

    int right=index+1;
    while(right<n && arr[right] ==arr[index])
    {
        count++;
        right++;
    }

    return count;
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
