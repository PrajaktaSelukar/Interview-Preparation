#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
	if(i == j)
		return true;
	
	if(i > j)
		return true;
			
	while(i < j)
	{
		if(s[i] != s[j])
			return false;
		i++;
		j--;	 
	}
	return true;
}

int minPalinPartition(string X, int i, int j)
{
	if (i >= j) 
		return 0;
	
	if(isPalindrome(X, i, j))
		return 0;	
		
	int min = INT_MAX;

	for (int k = i; k <= j - 1; k++) 
	{
		int temp = 1 + minPalinPartition(X, i, k) + minPalinPartition(X, k + 1, j);

		if (temp < min)
			min = temp;
	}
	
	return min;		
}

int main()
{
	string s;
	cin>>s;
	
	int n = s.length();

	cout<<minPalinPartition(s, 0, n - 1)<<"\n";
	
}
