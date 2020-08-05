#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001]; 

int MCM(int arr[], int i, int j)
{
	if(i >= j)
	{
		dp[i][j]=0;
		return 0;
	}
	
	if(dp[i][j] != -1)
		return dp[i][j];
	
	int min=INT_MAX;
	
	for(int k=i; k<j; k++)
	{
		int tempAns = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		
		if(tempAns < min)
			min = tempAns;
	}
	
	return dp[i][j] = min;	 
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	memset(dp, -1, sizeof(dp));
		
	cout<<MCM(arr, 1, n-1)<<"\n";;	
	
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";	
	}
}
