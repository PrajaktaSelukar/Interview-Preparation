#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void seaparatePosNeg(int *arr, int n)
{
    const int pivot=0;
    int index = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] < pivot) //negative
        {
            swap(arr[index], arr[i]);
            index++;
        }
    }
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	seaparatePosNeg(arr, n);

    cout<<"\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

}
