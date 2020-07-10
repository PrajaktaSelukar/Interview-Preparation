#include<iostream>
using namespace std;

int main()
{
	int t, n;
	cin>>t>>n;
	
	int arr[n], cache[n+1];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	cache[0]=0;	
	for(int i=0; i<n; i++)
		cache[i+1]=cache[i]+arr[i];
	
	while(t--)
	{
		int i, j;
		cin>>i>>j;
		
		cout<<cache[j+1]-cache[i]<<"\n";
	}
}
