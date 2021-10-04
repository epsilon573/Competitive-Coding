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

ll asked = 0;
vector<vector<ll>> adj;
vector<ll> euler;

ll query(set<ll>& s)
{
    assert(s.size()>1);

    asked++;
    assert(asked<13);

    cout << "? " << s.size() << " ";
    for(auto x : s)
        cout << x+1 << " ";
    cout << endl;

    ll res; cin >> res;
    return res;
}

void dfs(ll node,ll par)
{
    euler.pb(node);

    for(auto x : adj[node])
    {
        if(x==par) continue;

        dfs(x,node);
        euler.pb(node);
    }

    return;
}

bool solve()
{
    ll n;
    cin >> n;
    
    adj.assign(n, vector<ll>());
    set<ll> curr;

    for(ll i=1,x,y ; i<n ; ++i)
    {
        cin >> x >> y;
        x--,y--;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(ll i=0 ; i<n ; ++i) curr.insert(i);

    ll maxm = query(curr);
    dfs(0,-1);

    ll sz = euler.size();

    ll low=0 ,high=sz;
    while(low+1<high)
    {
        ll mid = (low+high)/2;

        curr = set<ll>(euler.begin()+low,euler.begin()+mid+1);
        ll q = query(curr);

        if(q==maxm)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    assert(high-low==1);
    cout << "! ";
        cout << euler[low]+1 << " " << euler[high]+1 << endl;
    return true;    
}

int main()
{
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