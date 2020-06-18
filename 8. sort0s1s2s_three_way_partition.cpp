#include<iostream>
using namespace std;

void sort0s1s2s(int *arr, int n)
{
    int low=0, high=n-1, mid=0;
    int pivot=1;
    //separates values into groups

    while(mid <= high)
    {
        cout<<arr[mid]<<" "<<low<<" "<<mid<<" "<<high<<endl;
        if(arr[mid] < pivot) // means its 0
        {
            swap(arr[mid], arr[low]);
            ++mid;
            ++low;
        }
        else if(arr[mid] > pivot) // means its 2
        {
            swap(arr[mid], arr[high]);
            --high;  //don't increment mid bcoz after interchanging new mid may be 0, 1 or 2
        }
        else //means its 1, so just go on
        {
            ++mid;;
        }
    }
    return;
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
