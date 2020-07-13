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
	
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=Sum; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return dp[n][Sum];
	
}

int main()
{
	int n, sum;
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	cin>>sum;	
	
	cout<< countSubsetForGivenSum(arr, sum, n);
}
