#include<iostream>
using namespace std;

int recursiveKnapSack(int wt[], int val[], int W, int n)
{
	if(n==0 || W==0)
		return 0;
	
	if(wt[n-1] <= W)
	{
		int include = val[n-1] + recursiveKnapSack(wt, val, W-wt[n-1], n-1);
		int exclude = recursiveKnapSack(wt, val, W, n-1);
		return max(include, exclude); 
	}
	
	else if(wt[n-1] > W)
	{
		return recursiveKnapSack(wt, val, W, n-1);
	}
}

int main()
{
	int n, W;
	cin>>n;
	int wt[n], val[n];
	
	for(int i=0; i<n; i++)
		cin>>wt[i];
	
	for(int i=0; i<n; i++)
		cin>>val[i];
		
	cin>>W;	
	
	cout<<recursiveKnapSack(wt, val, W, n);	
}
