#include<iostream>
using namespace std;

int missingNumberInArray(int arr[], int n)
{
    int sum = (n+1)*(n+2)/2;

    for(int i=0; i<n; i++)
    {
        sum -= arr[i];
    }

    return sum;

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\n";
    cout<<missingNumberInArray(arr, n);

}
