#include<iostream>
using namespace std;

void findUnion(int *arr1, int* arr2, int n, int m)
{
	int i=0, j=0;
	while(i<n && j<m)
	{
		if(arr1[i] < arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;
		}
		else if(arr1[i] > arr2[j])
		{
			cout<<arr2[j]<<" ";
			j++;
		}	
		else
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
		}
	}
	
	while(i<n)
	{
		cout<<arr1[i++]<<" ";
	}
	while(j<m)
	{
		cout<<arr2[j++]<<" ";
	}	
}

void findIntersection(int *arr1, int* arr2, int n, int m)
{
	int i=0, j=0;
	int count=0;
	while(i<n && j<m)
	{
		if(arr1[i] < arr2[j])
		{
			i++;
		}
		else if(arr1[i] > arr2[j])
		{
			j++;
		}	
		else
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
			count=1;
		}
	}
	if(count==0)
		cout<<"-1";
	
}

int main()
{	
	cout<<"Enter size of two sorted arrays :\n";
	int n, m;
	cin>>n>>m;
	cout<<"First array : \n";
	int arr1[n], arr2[m];
	for(int i=0; i<n; i++)
		cin>>arr1[i];
	cout<<"Second array : \n";
	for(int i=0; i<m; i++)
		cin>>arr2[i];
	
	cout<<"\nUnion : ";
	findUnion(arr1, arr2, n, m);
	
	cout<<"\nIntersection : ";
	findIntersection(arr1, arr2, n, m);
}
