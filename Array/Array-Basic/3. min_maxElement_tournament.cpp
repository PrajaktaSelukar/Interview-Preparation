#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct MM
{
    int min;
    int max;
};

struct MM min_maxElement(int arr[], int low, int high)
{
    struct MM minimax, mleft, mright;
    int mid;

    if(low == high)
    {
        minimax.min = arr[low];
        minimax.max = arr[low];
        return minimax;
    }

    if(high == low+1)
    {
        if(arr[low] > arr[high])
        {
            minimax.min = arr[high];
            minimax.max = arr[low];
        }

        else
        {
            minimax.min = arr[low];
            minimax.max = arr[high];
        }
            return minimax;
    }

    mid = (low+high)/2;
    mleft = min_maxElement(arr, low, mid-1);
    mright = min_maxElement(arr, mid+1, high);

    if(mleft.min > mright.min)
        minimax.min = mright.min;
    else
        minimax.min = mleft.min;

    if(mleft.max < mright.max)
        minimax.max = mright.max;
    else
        minimax.max = mleft.max;

    return minimax;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    struct MM minmax = min_maxElement(arr, 0, n-1);
    cout<<"\nMinimum element : "<<minmax.min;
    cout<<"\nMaximum element : "<<minmax.max;
}
