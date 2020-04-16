#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

vector<int> adj[maxn],lvl(maxn),parent(maxn);
vector<ll> sum(maxn);
vector<bool> vis(maxn);

void dfs(ll node, ll par)
{
    vis[node]=true;
    parent[node] = par ;
    lvl[node] = lvl[par]+1;
    sum[node] = 1;

    for(auto x : adj[node])
    {
        if(!vis[x] && x!=parent[node])
           {    
              dfs(x,node);
              sum[node] += sum[x]; 
           }
    }    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    int n,k,ans=0;
    cin >> n >> k;

    for (int i = 0; i < n-1 ; ++i)
    {
        ll u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0);
    vector<ll> v;

    for(int i=1 ; i<=n ; ++i)
    {
        v.pb( lvl[i] - sum[i] );
    }

    sort(v.begin() , v.end() , greater<ll> ());

    cout << accumulate(v.begin(),v.begin()+k,0LL) << endl;

    return 0;
} 