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

vector<vector<ll>> adj;
vector<ll> best,in,vis;
ll timer;

void dfs(ll node, ll parent)
{
    vis[node] = 1;
    in[node] = best[node] = timer++;

    for(auto child : adj[node])
    {
        if(child==parent) continue;

        // this is a back edge i.e. it knows an ancestor
        if(vis[child])
        {
            // update it to the greatest(best) ancestor it knows
            best[node] = min(best[node],in[child]); 
        }
        else
        {
            dfs(child,node);

            // if child knows no ancestor i.e. best[child]==in[child]
            // it is a bridge
            if(best[child]==in[child])
            {
                cout << "(" << node << "," << child << ") is a bridge" << endl; 
            }

            // if child knows a better ancestor, update it in the parent
            best[node] = min(best[node],best[child]);
        }
    }

    return;
}

bool solve()
{
    ll n,m;
    cin >> n >> m;

    adj.resize(n+1);
    best.resize(n+1);
    in.resize(n+1);
    vis.assign(n+1,0);

    for(ll i=0,x,y ; i<m ; ++i)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1);

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
