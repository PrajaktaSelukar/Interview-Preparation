#include<iostream>
using namespace std;

bool SubsetSumProblem(int arr[], int Sum, int n)
{
	bool dp[n+1][Sum+1];
	
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<Sum+1; j++)
		{
			if(i==0)
				dp[i][j]=false;
			
			if(j==0)
				dp[i][j]=true;	
		}
	}
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<Sum+1; j++)
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
	
	if(SubsetSumProblem(arr, sum, n))
		cout<<"Yes... Such subset exists";
	
	else
		cout<<"No... Such subsets does not exist";	
}
