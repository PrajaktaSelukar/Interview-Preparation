#include<iostream>
using namespace std;

int MCM(int arr[], int i, int j)
{
	if(i >= j)
		return 0;
	
	int min=INT_MAX;
	
	for(int k=i; k<j; k++)
	{
		int tempAns = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		
		if(tempAns < min)
			min = tempAns;
	}
	
	return min;	 
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	cout<<MCM(arr, 1, n-1);	
}
