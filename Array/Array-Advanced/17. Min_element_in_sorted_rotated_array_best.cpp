#include<iostream>
using namespace std;

int find_min_ele(int arr[], int n)
{
    if(n == 0)
        return -1;

    if(n == 1)
        return arr[0];

    int low=0;
    int high=n-1;

    while(low < high)
    {
        int mid = low + (high-low)/2; //to avoid overflow

        if(arr[mid] < arr[high])
            high = mid;

        else
            low = mid+1;
    }
    return arr[low];
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\nMinimum element in sorted and rotated array is : "<<find_min_ele(arr, n)<<"\n";
}
