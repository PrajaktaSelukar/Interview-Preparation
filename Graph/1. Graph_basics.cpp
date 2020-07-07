#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    unordered_map<int, list<pair<int, int> > > adjList;
public:
    void addEdge(int u, int v, int wt, int bidir)
    {
        adjList[u].push_back(make_pair(v, wt));
        if(bidir)
            adjList[v].push_back(make_pair(u, wt));
    }

    void printAdjacencyList()
    {
        for(auto p:adjList)
        {
            int a = p.first;
            list<pair<int, int> > nbrs = p.second;
            cout<<a<<" -> ";

            for(auto nbr:nbrs)
            {
                int b = nbr.first;
                int wt = nbr.second;
                cout<<" ("<<b<<", "<<wt<<")";
            }
            cout<<"\n";
        }
    }

};

int main()
{
    Graph g;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a, b, wt;
        cin>>a>>b>>wt;
        g.addEdge(a, b, wt, 1);
    }

    g.printAdjacencyList();

}
