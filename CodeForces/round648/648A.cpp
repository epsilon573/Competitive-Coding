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
        ll n,m; cin >> n >> m; 
        vector<vector<ll>> v(n,vector<ll> (m));
        for(ll i=0 ; i<n ; ++i)
            for(ll j=0 ; j<m ; ++j) cin >> v[i][j];

                ll row = 0;
                for(ll i=0 ; i<n ; ++i)
                {
                    ll j=0;
                    for(j=0 ; j<m ; ++j)
                    {
                        if(v[i][j]==1) break;
                    }
                    if(j==m)  row++;    
                }

                ll col = 0;
                for(ll i=0 ; i<m ; ++i)
                {
                    ll j=0;
                    for(j=0 ; j<n ; ++j)
                    {
                        if(v[j][i]==1) break;
                    }
                    if(j==n)  col++;    
                } 

                ll ans = min(row,col);

                if(ans&1) cout << "Ashish" << endl;
                else cout << "Vivek" << endl;               
    }

    return 0;
} 