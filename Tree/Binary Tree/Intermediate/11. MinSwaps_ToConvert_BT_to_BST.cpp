#include<bits/stdc++.h>
using namespace std;

void inorder(int* arr, vector<int> &vec, int n, int index)
{
    if(index >= n)
        return;

    inorder(arr, vec, n, 2*index + 1);

    vec.push_back(arr[index]);

    inorder(arr, vec, n, 2*index + 2);
}

//function to find minimum swaps to convert an array to a sorted array
int minSwaps(vector<int> vec, int n)
{
    vector<pair<int, int> > st(vec.size());

    int ans=0;
    for(int i=0; i<n; i++)
    {
        st[i].first = vec[i];
        st[i].second = i;
    }

    sort(st.begin(), st.end());

    for(int i=0; i<n; i++)
    {
        //second element = i
        if(i == st[i].second)
            continue;

        else
        {
            swap(st[i].first, st[st[i].second].first);
            swap(st[i].second, st[st[i].second].second);
        }

        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> vec;
    inorder(arr, vec, n, 0);

    cout<<"\nMinimum swaps to convert Binary Tree to BST : "<<minSwaps(vec, n)<<endl;
}
