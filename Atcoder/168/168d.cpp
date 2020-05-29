// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

vector<ll> adj[maxn];
vector<ll> par(maxn,0);
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

    ll n,m;
    cin >> n >> m;

    for(ll i=0,x,y ; i<m  ; ++i)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    queue<ll> q;
    q.push(1);
    par[1] = 1;
    
    while(!q.empty())
    {
        ll z = q.front();
        q.pop();

        for(auto x : adj[z])
        {
            if(!par[x])
            {
                q.push(x);
                par[x] = z;
            }
        }
    }

    for(ll i=2 ; i<=n ; ++i)
    {
        if(!par[i])
        {
            cout << "No" ; return 0;
        }
    }
    
    cout << "Yes" << endl;

    for(ll i=2 ; i<=n ; ++i)
    {
        cout << par[i] << endl;
    }
    return 0;
}  