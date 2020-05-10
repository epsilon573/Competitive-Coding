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
    vector<ll> v(n+1);

    for(ll i=0 ; i<n ; ++i) cin >> v[i+1];

    for(ll i=0,a,b ; i<m ; ++i)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll cnt=0;

    for(ll i=1 ; i<=n ; ++i)
    {
        bool flag = true;
        for(auto x : adj[i])
        {
            if(v[x] >= v[i])
            {
                flag = false;
                break;
            }
        }

        if(flag) cnt++;
    }    

    cout << cnt;

    return 0;
} 