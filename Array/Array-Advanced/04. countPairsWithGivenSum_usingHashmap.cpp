#include<iostream>
#include<unordered_map>
using namespace std;

int countPairsWithGivenSum(int arr[], int n, int sum)
{
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
        mp[arr[i]]++;

    int count=0;

    for(int i=0; i<n; i++)
    {
        count += mp[sum-arr[i]];

        if(sum-arr[i] == arr[i])
            count--;
    }
    return count/2;
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
