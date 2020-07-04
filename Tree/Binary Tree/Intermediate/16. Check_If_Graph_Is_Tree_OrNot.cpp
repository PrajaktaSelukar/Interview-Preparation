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

    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;

        for(auto nbr : adjList[node])
        {
            if(!visited[nbr])
            {
                //Go and recursively visit neighbour
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if(cycle_mila)
                    return true;
            }
            //nbr is visited but nbr should not be the parent
            else if(nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool checkGraphIsTree(int V)
    {
        bool *visited = new bool[V];

        for(int i=0; i<V; i++)
            visited[i]=false;

        if(cycle_helper(0, visited, -1))
            return false;

        for(int i=0; i<V; i++)
        {
            if(!visited[i])
                return false;
        }
        return true;
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

    if(g.checkGraphIsTree(n))
        cout<<"\nYes, the given Graph is a Tree\n";
    else
        cout<<"\nNo, the given Graph is not a Tree\n";
}
