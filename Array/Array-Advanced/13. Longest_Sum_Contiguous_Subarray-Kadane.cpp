#include<iostream>
using namespace std;

int max_Subarray_sum(int *arr, int n)
{
    int curr_max=0;
    int max_so_far=INT_MIN;

    for(int i=0; i<n; i++)
    {
        curr_max += arr[i];

        if(curr_max < arr[i])
            curr_max = arr[i];

        if(max_so_far < curr_max)
            max_so_far = curr_max;
    }

    return max_so_far;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Longest Sum Contiguous Array : "<<max_Subarray_sum(arr, n)<<"\n";
}
