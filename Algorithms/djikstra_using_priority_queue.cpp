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
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> vis(52*n,0),dis(52*n,inf);
    vector<vector<pair<ll,ll>>> adj(n);

    for(ll i=0,x,y,w ; i<m ; ++i)
    {
        cin >> x >> y >> w;
        --x,--y;
        adj[x].emplace_back(y,w);
        adj[y].emplace_back(x,w);
    }
    
    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;

    dis[0] = 0;
    q.push({0,0});

    while(!q.empty())
    {
        auto curr = q.top();
        ll node = curr.second,wt = curr.first, left = curr.second%51;

        q.pop();

        if(vis[node]) continue;

        vis[node] = 1;
        dis[node] = wt; 

        for(auto x : adj[node/51])
        {
            ll child = x.first, wt_child = x.second;
            ll to_weight = (left+wt_child)*(left+wt_child) , des = child*51;
            
            // if this is the first edge
            if(!left)
            {
                to_weight = 0;
                des = child*51 + wt_child;
            }

            if( wt + to_weight < dis[des])
            {
                dis[des] = wt + to_weight;
                q.push({dis[des],des});
            }
        }
    }

    for(ll i=0 ; i<n ; ++i)
    {
        if(dis[i*51]==inf) cout << -1 << " ";
        else cout << dis[i*51] << " ";
    }
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
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 