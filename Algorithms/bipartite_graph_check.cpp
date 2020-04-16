#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e3+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

vector<ll> adj[maxn],color(maxn);
vector<bool> vis(maxn);

bool dfs(ll node , ll c)
{
    bool ans = true;

    color[node] = c;
    vis[node] = true;
    
    for(auto x : adj[node])
    {
        if(!vis[x]) 
        {
            ans &= dfs(x , c^1); 
        }
        
        if(color[x] == color[node]) ans = false;

        if(!ans) return ans;
    }

    return ans;
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

    ll t,n,k;
    cin >> t;

    for(ll z=1 ; z<=t ; ++z)
    {
        for(ll i=0 ; i<maxn ; ++i)
        {
            adj[i].clear();
            vis[i] = false;
            color[i] = 0;
        }

        cin >> n >> k;
        for(ll i=0 ; i<k ; ++i)
        {
            ll a,b;
            cin >> a >> b;

            adj[a].pb(b);
            adj[b].pb(a);
        }
         
        string str = "No suspicious bugs found!";
         
        cout << "Scenario #" << z << ":\n";
        for(ll i=1 ; i<=n ; ++i)
        {
            if(!vis[i]) 
                if(!dfs(i,0))
                    str = "Suspicious bugs found!";
        }
        cout << str << endl;
    }

    return 0;
} 