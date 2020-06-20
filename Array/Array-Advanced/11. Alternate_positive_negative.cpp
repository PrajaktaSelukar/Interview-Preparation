#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateRight(int* arr, int n, int outOfPlace, int curr)
{
    int temp = arr[curr];

    for(int i=curr; i>outOfPlace ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[outOfPlace] = temp;
}

void alternatePositiveNegative(int *arr, int n)
{
    int outOfPlace = -1;

    for(int index=0; index<n; index++)
    {
        if(outOfPlace >= 0)
        {
            if( ( (arr[index] >= 0) && arr[outOfPlace] < 0)
                ||  ((arr[index] < 0) && arr[outOfPlace] >= 0 ))
            {
                rotateRight(arr, n, outOfPlace, index);

                if(index - outOfPlace >= 2)
                    outOfPlace += 2;
                else
                    outOfPlace = -1;
            }
        }

        if(outOfPlace == -1)
        {
            if( ((arr[index] >= 0) && (!(index & 0x01)) )
                    || ((arr[index] < 0) && (index & 0x01)) )
            {
                outOfPlace = index;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    alternatePositiveNegative(arr, n);

    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
