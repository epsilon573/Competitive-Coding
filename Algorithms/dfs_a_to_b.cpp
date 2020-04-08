#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

vector<ll> v[maxn],path,vis(maxn);

void addEdge(ll x, ll y) 
{ 
    v[x].pb(y); 
    v[y].pb(x); 
} 
 
void printPath() 
{ 
    ll i; 
    for (i = 0; i < (ll)path.size() - 1; i++) { 
        cout << path[i] << " -> "; 
    } 
    cout << path[i]; 
} 

void DFS(ll x,  ll y) 
{ 
    path.pb(x); 
    if (x == y) 
    { 
        printPath(); 
        return; 
    } 
    vis[x] = true; 
 
    if (!v[x].empty()) { 
        for (ll j = 0; j < v[x].size(); j++) { 
            if (vis[v[x][j]] == false) { 
                DFS(v[x][j], y);  
            } 
        } 
    } 
    
    path.pop_back(); 
     
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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        for(ll i=0 ; i<n-1 ; ++i)
        {
            ll a,b;
            cin >> a >> b;
            addEdge(a,b);
        }

        DFS(1,3);
    }

    return 0;
} 