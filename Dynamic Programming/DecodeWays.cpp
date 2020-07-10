#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int dp[1001];

bool isValid(string s)
{
	if(s.size() == 0 || s[0]=='0')
		return false;

	int value = atoi(s.c_str());

	return value>=1 && value<=26;
}

int numDecoding(string s, int decodePointer)
{
	if(decodePointer >= s.size())
		return 1;

	if(dp[decodePointer] != -1)
		return dp[decodePointer];

	int totalDecomposition = 0;
	for(int i=1; i<=2; i++)
	{
		if(decodePointer + i <= s.size())
		{
			string snippet = s.substr(decodePointer, decodePointer + i);

			if(isValid(snippet))
				totalDecomposition += numDecoding(s, decodePointer);
		}
	}

	dp[decodePointer]=totalDecomposition;
	return dp[decodePointer];
}

int main()
{
	string s;
	cin>>s;

	memset(dp, -1, sizeof(dp));

	cout<<numDecoding(s, 0);
}
