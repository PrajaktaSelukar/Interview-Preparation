#include<bits/stdc++.h>
using namespace s td;

bool checkSubarray(int arr1[], int n1, int arr2[], int n2)
{
    int ptr1=0, ptr2=0;

    while(ptr1 < n1 && ptr2 <n2)
    {
        if(arr1[ptr1] == arr2[ptr2])
        {
            ptr1++;
            ptr2++;

            if(ptr2 == n2)
                return true;
        }
        else
        {
            ptr1 = ptr1 - ptr2 + 1;
            ptr2 = 0;
        }
    }
    return false;
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;

    int arr1[n1], arr2[n2];

    for(int i=0; i<n1; i++)
        cin>>arr1[i];

    for(int i=0; i<n2; i++)
        cin>>arr2[i];

    if(checkSubarray(arr1, n1, arr2, n2))
        cout<<"\nYes, Array 1 is a subarray of Array 2\n";
    else
        cout<<"\nNo, Array 2 is not a subarray of Array 2\n";
}
