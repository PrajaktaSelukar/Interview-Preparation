#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sort0s1s2s(int arr[], int n)
{
	int low=0;
	int high=n-1;
	int itr=0;
	
	while(itr <= high)
	{
		if(arr[itr] < 0)
		{
			swap(arr[itr], arr[low]);
			itr++;
			low++;
		}
		
		else if(arr[itr] == 0)
		{
			itr++;
		}
		
		else if(arr[itr] > 0)
		{
			swap(arr[itr], arr[high]);
			high--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	sort0s1s2s(arr, n);
	
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";	
	
}
