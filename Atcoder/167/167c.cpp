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

    ll n,m,x;
    cin >> n >> m >> x;
    ll min_cost = inf;

    vector<vector<ll>> v(n, vector<ll> (m));
    vector<ll> cost(n);

    for(ll i=0 ; i<n ; ++i)
    {
        cin >> cost[i];
        for(ll j=0; j<m ; ++j)
        {
            cin >> v[i][j];
        }
    } 

    for(ll i=0 ; i < (1 << n) ; ++i)
    {
        ll cst = 0;
        vector<ll> ans(m);
        for(ll j=0 ; j<n ; ++j)
        {
            if( (i >> j)&1 )
            {
                cst += cost[j];
                for(ll k=0 ; k<m ; ++k)
                {
                    ans[k] += v[j][k];
                }
            }
        }

        for(ll k=0 ; k<m ; ++k)
        {
            if(ans[k]<x) break;

            if(k==m-1)
            {
                min_cost = min(cst, min_cost);
            }
        }
    }
    
    if(min_cost!=inf)
    cout << min_cost;
    else
    cout << -1;

    return 0;
} 