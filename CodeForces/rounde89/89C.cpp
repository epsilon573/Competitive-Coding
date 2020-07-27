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

bool solve()
{
    ll n,m; cin >> n  >> m;
    vector<vector<ll>> v( n, vector<ll>(m) );
    vector<vector<ll>> mat( n*m );

    for(ll i=0 ; i<n ; ++i)
        for(ll j=0 ; j<m ; ++j)
            {
                cin >> v[i][j];

                ll dist1 = abs(i) + abs(j);
                ll dist2 = abs(n-1-i) + abs(m-1-j);

                if(dist1==dist2) continue;
                else
                    mat[ min(dist1,dist2) ].pb(v[i][j]);
            }


    ll ans = 0;
    for(ll i=0 ; i<mat.size() ; ++i)
    {
       // cout << "Matrix " << i << " " << endl;
       // for(auto x : mat[i]) cout << x << " "; cout << endl;
        ans += min( count(mat[i].begin(),mat[i].end(),0) , count(mat[i].begin(),mat[i].end(),1)  ) ;
    }        

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

    ll t;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this
        }
    }

    return 0;
} 