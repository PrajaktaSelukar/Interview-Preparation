#include<bits/stdc++.h>
using namespace std;

/*
Brute force(O(n*m) ) - count 1s in each row and find the max of them
*/

int medianInSortedMat(int mat[][100], int n, int m)
{
    int min=INT_MAX, max=INT_MIN;

    int final_count = (n*m + 1)/2;

    for(int i=0; i<n; i++)
    {
        if(mat[i][0] < min)
            min = mat[i][0];

        if(mat[i][m-1] > max)
            max = mat[i][m-1];
    }

    while(min < max)
    {
        int count=0;
        int mid = min + (max-min)/2;


        //count elements smaller than median
        for(int i=0; i<n; ++i)
            count += (upper_bound(mat[i], mat[i]+m, mid)- mat[i]);

        if(count < final_count)
            min = mid+1;
        else
            max = mid;
        cout<<count<<" "<<min<<" "<<max<<"\n";
    }
    return min;
}

int main()
{
    int n, m;
    cin>>n>>m;

    int mat[100][100];
    cout<<"\nEnter elements sorted order row-wise\n";

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<"\nMedian in row-wise sorted matrix : "<<medianInSortedMat(mat, n, m)<<"\n";
}
