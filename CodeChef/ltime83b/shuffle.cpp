#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n),sv(n);

    for(ll i=0 ; i<n ; ++i) cin >> sv[i];
    v = sv;
        
    sort(sv.begin(),sv.end());
        
    map<ll,vector<ll>> m;

    for(ll i=0 ; i<n ; ++i)
    {
        m[sv[i]].pb(i%k);
    }

    for(ll i=0 ; i<n ; ++i)
    {
        auto it = find( m[v[i]].begin() , m[v[i]].end() , i%k) ;
        if( it == m[v[i]].end() )
        {
            cout << "no" << endl; return;
        }
        else
        {
            m[v[i]].erase(it);
        }
    }

    cout << "yes" << endl;        

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
        solve();
    }

    return 0;
} 