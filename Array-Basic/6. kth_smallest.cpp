#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low;

	for(int j=low; j<high; j++)
	{
		if( arr[j]<=pivot )
		{
			swap( &arr[i], &arr[j] );
			i++;
		}
	}
	swap( &arr[high], &arr[i] );
	return i;
}

int partition_r(int arr[], int low, int high)
{
	int n=rand();
	srand( time(NULL) );
	int random = low + n % (high - low + 1);
	swap( &arr[random], &arr[high] );
	return partition(arr, low, high);
}

int kth_smallest(int arr[], int low, int high, int k)
{
	if(low > high)
		return -1;

	if (low == high)
      return arr[low];

	int q = partition_r(arr, low, high);

	int abs = q - low + 1;

	if(abs == k)
		return arr[q];

	if(k < abs)
		return kth_smallest(arr, low, q-1, k);

	if(k > abs)
		return kth_smallest(arr, q+1, high, k-abs);
}


void quickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pivot=partition_r(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}

int main()
{
	cout<<"Enter the elements to be sorted : ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements : \n";
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int k;
	cout<<"\nEnter the position of the element : ";
	cin>>k;
	cout<<"\nThe ith order element of the array is : "<<kth_smallest(arr, 0, n-1, k)<<"\n"<<endl;

	quickSort(arr, 0, n-1);

	cout<<"The sorted array is :\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

	return 0;
}
