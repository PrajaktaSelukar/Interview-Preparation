#include<iostream>
using namespace std;

int max_Subarray_Product(int *arr, int n)
{
    int curr_max = arr[0];
    int curr_min = arr[0];
    int final_max = arr[0];

    for(int i=1; i<n; i++)
    {
        int temp = curr_max;

        curr_max = max(arr[i], max(curr_max*arr[i], curr_min*arr[i]));
        curr_min = min(arr[i], min(temp*arr[i], curr_min*arr[i]));

        if(final_max < curr_max)
            final_max = curr_max;

        cout<<curr_max<<" "<<curr_min<<" "<<final_max<<endl;
    }

    return final_max;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\nLongest Product Contiguous Subarray : "<<max_Subarray_Product(arr, n)<<"\n";
}
