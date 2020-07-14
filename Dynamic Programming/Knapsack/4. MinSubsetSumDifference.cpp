#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MinSubsetSumDifference(int arr[], int range, int n)
{
	bool dp[n+1][range+1];
	
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<range+1; j++)
		{
			if(i==0)
				dp[i][j]=false;
			
			if(j==0)
				dp[i][j]=true;	
		}
	}
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<range+1; j++)
		{
			if(arr[i-1] <= j)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
			}
	
			else if(arr[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	vector<int> vec;
	for(int i=0; i<=range/2; i++)
	{
		if(dp[n][i]==true)
			vec.push_back(i);
	}
	
	int mn=INT_MAX;
	for(int i=0; i<vec.size(); i++)
		mn=min(mn, range-2*vec[i]);
	
	return mn;	
	
}

int main()
{
	int n, sum, range=0;
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		range+=arr[i];
	}
	
	cout<<MinSubsetSumDifference(arr, range, n);
}
