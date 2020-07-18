#include<iostream>
#include<string.h>
using namespace std;

int LongestCommonSequence(string X, string Y, int n, int m)
{
	int dp[n+1][m+1];
	
	for(int i=0; i<=n; i++)
		dp[i][0]=0;
	
	for(int j=0; j<=m; j++)
		dp[0][j]=0;	
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(X[i] == Y[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else
				dp[i][j] = 0;		
		}
	}
	
	return dp[n][m];
}

int main()
{
	string X, Y;
	cin>>X>>Y;
	
	cout<<LongestCommonSequence(X, Y, X.length(), Y.length());
}
