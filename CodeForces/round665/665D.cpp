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
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl 
  
// function to calculate no. of nodes in a subtree 
void numberOfNodes(ll s, ll e , vector<vector<ll>> &adj , vector<ll> &count1, vector<ll> &parent) 
{ 
    count1[s] = 1;
    parent[s] = e; 
    for (auto u = adj[s].begin() ; u != adj[s].end(); u++) { 
          
        // condition to omit reverse path 
        // path from children to parent 
        if (*u == e) 
            continue; 
          
        // recursive call for DFS 
        numberOfNodes(*u, s, adj , count1 , parent); 
          
        // update count[] value of parent using  
        // its children 
        count1[s] += count1[*u]; 
    } 
} 

bool solve()
{
    ll n,m,ans = 0;
    cin >> n;

    vector<ll> count1(n+1);
    vector<ll> parent(n+1); 
    vector<vector<ll>> adj(n+1);
    vector<ll> ncnt;

    vector<pair<ll,ll>> edges(n-1);
    
    for(ll i=1,x,y ; i<n ; ++i) 
    {
        cin >> x >> y;
        edges[i-1] = mp(x,y);
        adj[x].pb(y);
        adj[y].pb(x);   
    }

    numberOfNodes(1, 0, adj , count1 , parent);
    assert( count1[1] == n );

    cin >> m;
    vector<ll> fac(m);

    for(ll i=0 ; i<m ; ++i) cin >> fac[i];
    
    sort(fac.begin(),fac.end());
    
    for(auto edge : edges)
    {
        ll x = edge.first;
        ll y = edge.second;

        if( parent[x] == y )
            ncnt.pb(count1[x]*(count1[1]-count1[x]));
        else
            ncnt.pb(count1[y]*(count1[1]-count1[y]));
    }

    assert(ncnt.size() == n-1);

    sort(ncnt.begin(),ncnt.end());

    while( fac.size() < n-1 )
        fac.pb(1);

    sort(fac.begin(),fac.end());
    
    ll compensate = ncnt[n-2];

    for(ll i=0 ; i<n-2 ; ++i)
    {
        ans = (ans + (fac[i]%mod)*(ncnt[i]%mod))%mod;
    }

    for(ll i=n-2 ; i<fac.size() ; ++i )
    {
        compensate = (compensate%mod)*(fac[i]%mod);
        compensate %= mod;
    }

    ans += compensate;
    ans %= mod;
     
    cout << ans << endl;
    return true;    
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