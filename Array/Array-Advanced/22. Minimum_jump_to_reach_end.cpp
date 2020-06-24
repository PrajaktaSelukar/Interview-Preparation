#include<bits/stdc++.h>
using namespace std;

int findMinJump(int arr[], int start, int end, int n)
{
    int lookup[n];
    memset(lookup, 0, sizeof(lookup));

    if(start == end)
        return 0;

    if(start >= n || arr[start] == 0)
        return INT_MAX;

    int min_jump = INT_MAX;
    for(int k = start+1; k <= start+arr[start] && k<=end; k++)
    {
        int cost = findMinJump(arr, k, end, n);

        if(cost != INT_MAX)
            min_jump = min(min_jump, cost+1);
    }
    lookup[start] = min_jump;
    return min_jump;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\nThe minimum jump to reach the end : "<<findMinJump(arr, 0, n-1, n);
}
