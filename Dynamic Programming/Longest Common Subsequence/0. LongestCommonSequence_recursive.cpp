#include<iostream>
#include<string.h>
using namespace std;

int LongestCommonSequence(string X, string Y, int n, int m)
{
	if(n==0 || m==0)
		return 0;
	
	if(X[n-1] == Y[m-1])
		return 1 + LongestCommonSequence(X, Y, n-1, m-1);
	else
		return max(LongestCommonSequence(X, Y, n-1, m), LongestCommonSequence(X, Y, n, m-1));		
}

int main()
{
	string X, Y;
	cin>>X>>Y;
	
	cout<<LongestCommonSequence(X, Y, X.length(), Y.length());
}
