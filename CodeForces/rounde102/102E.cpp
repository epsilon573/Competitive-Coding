// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

vector<ll> d,p;
vector<vector<pair<ll, ll>>> adj;

void setup(ll n)
{
    adj.resize(n);
    d.resize(n);
    p.resize(n);

    for(auto &x : adj) x.clear();
    for(auto &x : d) x = inf;
    for(auto &x : p) x = -1;
}

void dijkstra(ll s) {

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});

    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if ( d[v] + len < d[to] ) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

bool solve()
{
    ll n,m;

    cin >> n >> m;
    setup(4*n+5);

    for(ll i=0,x,y,w ; i<m ; ++i)
    {
        cin >> x >> y >> w;
        x--,y--;

        // 00 -> 00,11 add cost of node
        adj[4*x].emplace_back(4*y,w);
        adj[4*y].emplace_back(4*x,w);
        adj[4*x].emplace_back(4*y+3,w);
        adj[4*y].emplace_back(4*x+3,w);

        // 00 -> 01 skip node... 00 -> 10 twice cost
        adj[4*x].emplace_back(4*y+1,0);
        adj[4*y].emplace_back(4*x+1,0);
        adj[4*x].emplace_back(4*y+2,2*w);
        adj[4*y].emplace_back(4*x+2,2*w);

        // 01 -> 11 add twice cost of node , 01 - add normal cost
        adj[4*x+1].emplace_back(4*y+3,2*w);
        adj[4*y+1].emplace_back(4*x+3,2*w);
        adj[4*x+1].emplace_back(4*y+1,w);
        adj[4*y+1].emplace_back(4*x+1,w);

        // 10 -> 11 skip cost of current node , 10 - add normal cost
        adj[4*x+2].emplace_back(4*y+3,0);
        adj[4*y+2].emplace_back(4*x+3,0);
        adj[4*x+2].emplace_back(4*y+2,w);
        adj[4*y+2].emplace_back(4*x+2,w);

        // 11 -> 11 add cost of current node
        adj[4*x+3].emplace_back(4*y+3,w);
        adj[4*y+3].emplace_back(4*x+3,w);
    }

    dijkstra(0);

    for(ll i=1 ; i<n ; ++i)
        cout << d[4*i+3] << " ";
    
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 