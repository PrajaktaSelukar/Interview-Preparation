#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//unordered_map<string, int> mp; 
int dp[1001][1001][2];

int evalExpressionToTrue(string s, int i, int j, bool isTrue)
{
	if(i>j)
		return false;
	
	if(i == j)
	{
		if(isTrue == true)
			return s[i]=='T';
		
		else 
			return s[i]=='F';				 
	}
	/*
	string temp = to_string(i);
	temp.push_back(" ");
	temp.append(to_string(j));
	temp.push_back(" ");
	temp.append(to_string(isTrue));
	
	if(mp.find(temp) != mp.end())
		return mp[temp];
	*/
	
	if(dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];
	
	int ans=0;
	
	for(int k=i+1; k<j; k=k+2)  //bracket will be on operators
	{
		int leftTrue = evalExpressionToTrue(s, i, k-1, true);
		int leftFalse = evalExpressionToTrue(s, i, k-1, false);
		int rightTrue = evalExpressionToTrue(s, k+1, j, true);
		int rightFalse = evalExpressionToTrue(s, k+1, j, false);
		
		if(s[k] == '&')
		{
			if(isTrue == true) // both must be true
				ans += leftTrue*rightTrue;
			else
				ans += leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse;	
		}
		
		else if(s[k] == '|')
		{
			if(isTrue == true) 
				ans += leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
			else
				ans += leftFalse*rightFalse;
		}
		
		else if(s[k] == '^')
		{
			if(isTrue == true) 
				ans += leftTrue*rightFalse + leftFalse*rightTrue;
			else
				ans += leftFalse*rightFalse + leftTrue*rightTrue;
		}
	}	
	
	//return mp[temp] = ans;
	return dp[i][j][isTrue] = ans;
}

int main()
{
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	//mp.clear();
	memset(dp, -1, sizeof(dp));
			
	cout<<evalExpressionToTrue(s, 0, n-1, true);		
}
