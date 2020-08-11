#include<bits/stdc++.h>
using namespace std;

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
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	string s;
	
	cin>>s;
			
	cout<<evalExpressionToTrue(s, 0, n-1, true);		
}
