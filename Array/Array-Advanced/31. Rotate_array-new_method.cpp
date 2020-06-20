#include<bits/stdc++.h>
using namespace std;

void printArray(int nums[], int n)
{
	for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
    cout<<endl;    
}

//swap the last k elements with he first k elements
void rotate_array(int nums[], int k, int n)
{
	for( ; k=k%n; n-=k, nums+=k)
	{
		for(int i=0; i<k; i++)
		{
			swap(nums[i], nums[n-k+i]);
			printArray(nums, n);
		}
			
	}
}

int main()
{
    int n;
    cin>>n;

    int tmp;
    int nums[n];
    for(int i=0; i<n; i++)
    {
    	cin>>nums[i];
    }

    int k;
    cin>>k;

    rotate_array(nums, k, n);

    printArray(nums, n);
}
