#include<iostream>
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
        adj = new list<int> [V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bfs(int src, vector<bool>& visited)
    {
        vector<int> parent(V, -1);
        queue<int> q;
        visited[src]=true;
        q.push(src);

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
                    parent[nbr] = node;
                }
                else if(parent[node] != nbr)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCycle()
    {
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++)
            if(!visited[i] && bfs(i, visited))
                return true;

        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    if(g.checkCycle())
        cout<<"Yes, there is a cycle";
    else
        cout<<"No, there is no cycle";
}
