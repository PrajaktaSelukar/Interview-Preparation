#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minEditDistance(string str1, string str2)
{
	int n = str1.size();
	int m = str2.size();
	
	int dp[m+1][n+1];
	
	for(int i=0; i<=m; i++)
		dp[i][0]=i;
		
	for(int j=0; j<=n; j++)
		dp[0][j]=j;
		
	
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			
			else
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));	
		}
	}
	
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}	
	
	return dp[m][n];
}

int main()
{
	string s1, s2;
	cin>>s1>>s2;
	
	cout<<"\n"<<minEditDistance(s1, s2);			
}
