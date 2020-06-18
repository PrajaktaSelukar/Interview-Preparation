#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a;
    int temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        a.push_back(temp);
    }

    int k;
    cin>>k;

    nth_element(a.begin(), a.begin()+k, a.end());

    cout<<"\nKth element is : "<<a[k-1]<<endl;
}
