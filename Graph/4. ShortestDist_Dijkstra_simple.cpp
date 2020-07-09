#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

const long long N = 1e5+1;
bool visit[N+1];

vector<pair<ll, ll> > adj[N+1];
ll dist[N+1];

void dijkstra()
{
    dist[1]=0;
    multiset<pair<ll,ll>> s;
    s.insert(mp(0,1));

    while(!s.empty())
    {

        pair<ll,ll> p =*s.begin();
        s.erase(s.begin());

        ll node = p.second;
        if(!visit[node])
        {
            visit[node]=1;
            for(ll i =0;i<adj[node].size(); i++)
            {
                ll cost=adj[node][i].first;
                ll to=adj[node][i].second;

                if(dist[node]+cost<dist[to])
                {
                    dist[to]=dist[node]+cost;
                    s.insert(mp(dist[to],to));
                }

            }
        }

    }
}

void init(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        visit[i]=0;
        dist[i]=INT_MAX;
        adj[i].clear();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		init(n+1);
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(mp(1,v));
			adj[v].push_back(mp(1,u));

        }
        dijkstra();
        cout<<dist[n]<<endl;
    }

    return 0;
}
