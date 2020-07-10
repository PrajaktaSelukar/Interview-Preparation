#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
	int *dp = new int[n];
	for(int i=0; i<n; i++)
		dp[i]=1;
		
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}	
	
	for(int i=0;i<n;i++)
		cout<<dp[i]<<" ";
	cout<<"\n";	
	
	int ans = INT_MIN;
	for(int i=0;i<n;i++)
    	ans = max(ans,dp[i]);
	
	delete[] dp;
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	cout<<longestIncreasingSubsequence(arr, n);	
}
