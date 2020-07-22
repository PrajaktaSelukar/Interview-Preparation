#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string LongestCommonSequence(string X, string Y, int n, int m)
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
			if(X[i-1] == Y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else
				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );		
		}
	}
	
	int i=n, j=m;
	string s="";
	
	while(i>0 && j>0)
	{
		if(X[i-1] == Y[j-1])  // common then write once
		{
			s.push_back(X[i-1]);
			i--;
			j--;
		}
		else  // go to maximum side
		{
			if(dp[i-1][j] < dp[i][j-1]) 
			{
				s.push_back(Y[j-1]);  // first push the other
				j--;                  // then move to maximum side
			}
				
			else
			{
				s.push_back(X[i-1]); 
				i--;	
			}
		}
	}
	
	while(i>0)
	{
		s.push_back(X[i-1]); 
		i--;
	}
	
	while(j>0)
	{
		s.push_back(Y[j-1]);  
		j--; 
	}
	
	reverse(s.begin(), s.end());
	
	return s;
}

int main()
{
	string X, Y;
	cin>>X>>Y;
	
	cout<<LongestCommonSequence(X, Y, X.length(), Y.length());
}
