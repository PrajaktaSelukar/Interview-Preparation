#include<iostream>
using namespace std;

/*
Brute force(O(n*m) ) - count 1s in each row and find the max of them
*/

int rowWithMaxOnes(bool mat[][100], int n, int m)
{
    int row = 0;
    int col = m-1;

    int currRowWithMaxOne = -1;
    while(row < n && col >=0)
    {
        //if its 1 then move left
        if(mat[row][col] == 1)
        {
            col--;
            currRowWithMaxOne = row;
        }
        //if its 0 then move downwards
        else if(mat[row][col] == 0)
        {
            row++;
        }
    }
    return currRowWithMaxOne;
}

int main()
{
    int n, m;
    cin>>n>>m;

    bool mat[100][100];
    cout<<"\nEnter 0s and 1s in sorted order rowwise\n";

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<"\nMaximum 1s present in row "<<rowWithMaxOnes(mat, n, m)<<"\n";
}
