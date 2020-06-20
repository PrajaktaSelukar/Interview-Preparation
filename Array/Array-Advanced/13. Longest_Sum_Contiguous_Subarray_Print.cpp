#include<iostream>
using namespace std;

void max_Subarray_sum(int *arr, int n)
{
    int curr_max=0;
    int max_so_far=INT_MIN;
    int start=0, end=0;
    int beg=0;  //stores starting index of positive sum sequence

    for(int i=0; i<n; i++)
    {
        curr_max += arr[i];

        if(curr_max < arr[i])
        {
            curr_max = arr[i];
            beg = i;
        }

        if(max_so_far < curr_max)
        {
             max_so_far = curr_max;
             start = beg;
             end = i;
        }
    }

    cout<<"\nLongest Sum Contiguous Array : "<<max_so_far<<"\n\n";

    for(int i=start; i<=end; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    max_Subarray_sum(arr, n);
}
