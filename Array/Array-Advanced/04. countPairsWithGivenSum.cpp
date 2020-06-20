#include<iostream>
#include<algorithm>
using namespace std;

int countPairsWithGivenSum(int arr[], int n, int sum)
{
    sort(arr, arr+n);
    int count=0;

    int low=0, high=n-1;

    while(low < high)
    {
        if(arr[low]+arr[high] == sum)
        {
            count++;
            low++;
            high--;
        }
        if(arr[low]+arr[high] < sum)
        {
            low++;
        }
        if(arr[low]+arr[high] > sum)
        {
            high--;
        }
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
    int sum;
    cin>>sum;

    cout<<"\n";
    cout<<countPairsWithGivenSum(arr, n, sum);

}
