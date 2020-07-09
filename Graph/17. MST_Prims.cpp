#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
            edges[i][j] = 0;
    }

    for(int i=0; i<n; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edges[u][v] = wt;
        edges[v][u] = wt;
    }

    cout<<"\n";
    prims(edges, n);

    for(int i=0; i<n; i++)
        delete [] edges;

    delete [] edges;
}
