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
const int inf  = 1e8+5;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

vector<vector<int>> adj, adj_rev, adj_scc;
vector<bool> used,solved;
vector<int> order, component, ans;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int recur(int v) {
    if(solved[v])
        return ans[v];

    for(auto x : adj_scc[v]){
        ans[v] += recur(x);
        ans[v] = min(ans[v],inf+1);
    }

    solved[v] = true;
    if(ans[v]==inf) ans[v] = 0;
    if(ans[v]<inf && ans[v]>1) ans[v] = 2;
    return ans[v]; 
}

bool solve()
{
    ll n,m;
    cin >> n >> m;

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    
    order.clear();
    ans.assign(n,0);
    solved.assign(n,false);
    adj.assign(n,vector<int>());
    adj_scc.assign(n,vector<int>());
    adj_rev.assign(n,vector<int>());

    ans[0] = 1;
    solved[0] = true;

    for(ll i=0 ; i<m ; ++i)
    {
        ll x,y;
        cin >> x >> y;
        x--,y--;

        if(x==y)
        {
            ans[x] += inf;
        }

        adj[x].pb(y);
        adj_rev[y].pb(x);
    }
    
    used.assign(n,false);

    for(ll i=0 ; i<n ; ++i)
        if(!used[i])
            dfs1(i);

    used.assign(n,false);
    reverse(order.begin(),order.end());

    for(auto v : order)
        if(!used[v]){
            dfs2(v);
            
            int root = component.front();
            for(auto u : component)
                roots[u] = root;
            root_nodes.pb(root);

            if(component.size()>1 && ans[root]<inf)
                ans[root] += inf;

            component.clear();
        }

    for(int v=0 ; v<n ; ++v)
        for(auto u : adj[v])
            if(roots[u] != roots[v])
                adj_scc[roots[u]].push_back(roots[v]);

    for(auto x : root_nodes){
        ans[x] = recur(x);
    }

    for(ll i=0 ; i<n ; ++i)
    {
        ll curr = ans[roots[i]];

        if(curr==0)
            cout << 0 << " ";
        else if(curr==1)
            cout << 1 << " ";
        else if(curr>inf)
            cout << -1 << " ";
        else if(curr>1)
            cout << 2 << " ";
        else
            assert(false);
    }

    cout << endl;
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
    cin >> t;

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