#include<iostream>
#include<string.h>
using namespace std;

static int dp[1001][1001];

int LongestCommonSequence(string X, string Y, int n, int m)
{
	if(n==0 || m==0)
		return 0;
		
	if(dp[n][m] != -1)  //value is already evaluated
		return dp[n][m];	
	
	if(X[n-1] == Y[m-1])
		return dp[n][m] = 1 + LongestCommonSequence(X, Y, n-1, m-1);
	
	else
		return dp[n][m] = max(LongestCommonSequence(X, Y, n-1, m), LongestCommonSequence(X, Y, n, m-1));
}

int main()
{
	string X, Y;
	cin>>X>>Y;
	
	memset(dp, -1, sizeof(dp));
	
	cout<<LongestCommonSequence(X, Y, X.length(), Y.length());
}
