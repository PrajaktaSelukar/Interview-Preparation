#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int v)
    {
        V=v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printShortestDistance(int src, int dest)
    {
        bool* visited = new bool[V]{0};
        int* dist = new int[V+1]{0};
        int* parent = new int[V]{-1};

        queue<int> q;
        q.push(src);
        visited[src]=true;
        dist[src]=0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr : adj[node])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    parent[nbr]=node;
                }
            }
        }

        cout<<"\nThe Shortest Distance between "<<src<<" and "<<dest<<" is "<<dist[dest]<<"\n\n";

        cout<<"The Shortest Path is \n";
        int temp=dest;
        while(temp != -1)
        {
            cout<<temp<<" <- ";
            temp = parent[temp];
        }

    }
};

int main()
{
    Graph g(8);

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(3,7);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(5,6);
    g.addEdge(6,7);

    int src, dest;
    cin>>src>>dest;

    g.printShortestDistance(src, dest);
}
