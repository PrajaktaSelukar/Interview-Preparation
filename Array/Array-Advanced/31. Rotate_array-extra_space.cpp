#include<bits/stdc++.h>
using namespace std;

void rotate_array(vector<int> &nums, int k)
{
    int n=nums.size();

    if(n==0 || k<=0)
        return;

    vector<int> vecCopy(n);
    for(int i=0; i<n; i++)
        vecCopy[i]=nums[i];

    for(int i=0; i<n; i++)
        nums[(i+k)%n] = vecCopy[i];
}

int main()
{
    int n;
    cin>>n;

    int tmp;
    vector<int>nums;
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        nums.push_back(tmp);
    }

    int k;
    cin>>k;

    rotate_array(nums, k);

    for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
}
