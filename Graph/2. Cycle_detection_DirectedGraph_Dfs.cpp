#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    map<int, list<int> > adjList;
public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
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

    bool contains_cycle(int V)
    {
        bool *visited = new bool[V];

        for(int i=0; i<V; i++)
            visited[i]=false;

        return cycle_helper(0, visited, -1);

        //If some vertices are no covered, use this
        //Helpful in disconnected graph
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
                return cycle_helper(i, visited, -1);
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
        g.addEdge(a, b);
    }

    if(g.contains_cycle(n))
        cout<<"\nIt contains a cycle\n";
    else
        cout<<"\nIt does not contain a cycle\n";
}
