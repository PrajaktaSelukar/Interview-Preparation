#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, list<pair<T, int> > >adj;
public:

    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        adj[u].push_back(make_pair(v, dist));
        if(bidir)
            adj[v].push_back(make_pair(u, dist));
    }

    void printAdj()
    {
        for(auto u : adj)
        {
            cout<<u.first<<" -> ";

            for(auto v: u.second)
            {
                cout<<"("<<v.first<<", "<<v.second<<") ";
            }
            cout<<"\n";
        }
    }

    void dijkstraSSSP(T src)
    {
        unordered_map<T, int> dist;

        //Set all distance to infinity
        for(auto u: adj)
            dist[u.first] = INT_MAX;

        //make a set to find out a node with minimum distance
        set<pair<int, T> > s;     //set sorts according to the first element

        dist[src]=0;
        s.insert(make_pair(0, src));

        while(!s.empty())
        {
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //Iterate over neighbors/children of current node
            for(auto childPair : adj[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    //In set/Priority_Queue, updation of a particular is not possible
                    //we have to remove the old pair, and insert the new pair to stimulation updation

                    T dest = childPair.first;
                    auto f= s.find(make_pair(dist[dest], dest));

                    if(f != s.end())
                        s.erase(f);

                   //Insert the new pair
                   dist[dest] = nodeDist + childPair.second;
                   s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        cout<<"\n";
        //Lets print distance to all other node from src
        for(auto d : dist)
        {
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }


    }
};

int main()
{

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);

    g.printAdj();
    g.dijkstraSSSP(1);
    cout<<"\n-----------------------------------------\n\n";

    Graph<string>India;

    India.addEdge("Amritsar", "Delhi", 1);
    India.addEdge("Amritsar", "Jaipur", 4);
    India.addEdge("Jaipur", "Delhi", 2);
    India.addEdge("Jaipur", "Mumbai", 8);
    India.addEdge("Bhopal", "Agra", 2);
    India.addEdge("Mumbai", "Bhopal", 3);
    India.addEdge("Agra", "Delhi", 1);

    India.printAdj();
    India.dijkstraSSSP("Amritsar");
}
