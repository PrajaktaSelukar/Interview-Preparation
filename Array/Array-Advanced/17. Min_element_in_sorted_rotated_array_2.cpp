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

        //if current element is less than previous element, then found it
        if(mid > 0 && arr[mid] < arr[mid-1])
            return arr[mid];

        else if(arr[low] <= arr[mid] && arr[mid] > arr[high])
            low = mid+1;

        else
            high = mid-1;
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

    cout<<"\nMinimum element in sorted and rotated array is : "<<find_min_ele(arr, n);
}
