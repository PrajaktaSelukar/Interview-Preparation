#include<bits/stdc++.h>
using namespace std;

void rotate_array(vector<int> &nums, int k)
{
    int n=nums.size();

    k=k%n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());

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
