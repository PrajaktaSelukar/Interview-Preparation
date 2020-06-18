#include<iostream>
using namespace std;

void sort0s1s2s(int *arr, int n)
{
    int count0=0, count1=0, count2=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
            count0++;
        else if(arr[i] == 1)
            count1++;
        else if(arr[i] == 2)
            count2++;
    }

    for(int i=0; i<count0; i++)
        arr[i]=0;

    for(int i=count0; i<(count0+count1); i++)
        arr[i]=1;

    for(int i=(count0+count1); i<n; i++)
        arr[i]=2;
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

    cout<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

}
