#include<iostream>
using namespace std;

int countSubsetForGivenSum(int arr[], int Sum, int n)
{
	int dp[n+1][Sum+1]={0};
	
	for(int i=0; i<=n; i++)
		dp[i][0]=1;
	
	for(int j=1; j<=Sum; j++)
		dp[0][j]=0;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=Sum; j++)
		{
			if(arr[i-1] <= j)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j]; 
			}
	
			else if(arr[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][Sum];
	
}

int main()
{
	int n, sumArr=0, sum=0, givenSum;
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		sumArr+=arr[i];
	}
	
	cin>>givenSum;
	
	sum = (givenSum + sumArr)/2;
	
	cout<< countSubsetForGivenSum(arr, sum, n);
}
