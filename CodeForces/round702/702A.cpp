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
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n,ans=0;
    cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    for(ll i=1 ; i<n ; ++i)
    {
        if(max(v[i],v[i-1]) <= 2*min(v[i],v[i-1]))
            continue;
        else
        {
            ll mxm = max(v[i],v[i-1]);
            ll mnm = min(v[i],v[i-1]);

            ll ratio = (mxm+mnm-1)/mnm,cnt=0,x=1;

            while(x<ratio)
            {
                x*=2; cnt++;
            }

            ans += cnt-1;
        }
    }
    
    cout << ans << endl;
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
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
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 