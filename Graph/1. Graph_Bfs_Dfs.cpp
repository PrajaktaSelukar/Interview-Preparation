#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    map<int, list<int> > adjList;
public:
    void addEdge(int u, int v, int bidir)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }

    void printAdjacencyList()
    {
        for(auto row:adjList)
        {
            int a = row.first;
            cout<<a<<" -> ";

            for(int nbr : row.second)
            {
                cout<<nbr<<" ";
            }
            cout<<"\n";
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        map<int, int> visited;
        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(int nbr : adjList[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfsVisit(int node, int V, bool *visited)
    {
        visited[node] = true;
        cout<<node<<" ";

        for(int nbr : adjList[node])
        {
            if(!visited[nbr])
                dfsVisit(nbr, V, visited);
        }
    }

    void dfs(int src, int V)
    {
        bool *visited = new bool[V];

        for(int i=0; i<V; i++)
            visited[i]=false;

        dfsVisit(src, V, visited);

        //If some vertices are no covered, use this
        //Helpful in disconnected graph
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
                dfsVisit(i, V, visited);
        }
    }

};

int main()
{
    Graph g;
    int n, e;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int a, b;
        cin>>a>>b;
        g.addEdge(a, b, 1);
    }

    int src;
    cout<<"\nEnter the source : ";
    cin>>src;
    cout<<"\nBreadth First Search :\n";
    g.bfs(src);

    cout<<"\nDepth First Search :\n";
    g.dfs(src, n);
}
