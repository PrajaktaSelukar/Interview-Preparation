#include<iostream>
#include<climits>
using namespace std;

int unboundedKnapSack(int coins[], int Sum, int n)
{
	int dp[n+1][Sum+1];
	for(int i=1; i<n+1; i++)
		dp[i][0]=0;
		
	for(int j=0; j<Sum+1; j++)
		dp[0][j]=INT_MAX -1;
	
	for(int j=1; j<Sum+1; j++)
	{
		if(j%coins[0] == 0)
			dp[1][j]=j/coins[0];
		else
			dp[1][j]=INT_MAX - 1;	
	}
	
	for(int i=2; i<n+1; i++)
	{
		for(int j=1; j<Sum+1; j++)
		{
			if(coins[i-1] <= j)
			{
				dp[i][j] = min( (dp[i][j-coins[i-1]] + 1), dp[i-1][j] ); 
			}
	
			else if(coins[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][Sum];
}

int main()
{
	int n, Sum;
	cin>>n;
	int coins[n];
	
	for(int i=0; i<n; i++)
		cin>>coins[i];
		
	cin>>Sum;	
	
	cout<<unboundedKnapSack(coins, Sum, n);	
}
