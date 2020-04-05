#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

vector<ll> varr[1000000];

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

    ll t,n;
    cin >> t;

    while(t--)
    {
    	ll flag = 0,ans = 1;
        cin >> n; 
        vector<ll> v(n);

        for(ll i=0 ; i<n ; ++i) varr[i].clear();

        for(ll i=0 ; i<n ; ++i) cin >> v[i];

        for(ll i=0 ; i<n ; ++i)
        {
        	if(v[i]==0) varr[i].pb(0);
        	for(ll j=0 ; (v[i] >> j) > 0 ; ++j)
            {
            	varr[i].pb( (v[i]>>j) & 1 );
            }
        }

        for(ll i=0 ; i<n-1 ; ++i)
        {
        	ll j;
        	for(j=0 ; j < min( varr[i].size() , varr[i+1].size() ) ; ++j)
        	{
                if( varr[i+1][j] == 0 && varr[i][j] == 1) { flag = 1; break; }
                if( varr[i+1][j] == 1 && varr[i][j] == 1) ans = (ans*2LL)%mod;
        	}
        	if(flag) break;
        }

        if(flag) cout << 0 << endl;
        else 
        	cout << ans << endl;

    }

    return 0;
} 