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
    ll n;
    cin >> n;
    vector<ll> v(n+2,0),pref(n+2,-1),suff(n+2,-1);

    for(ll i=1 ; i<=n ; ++i) cin >> v[i];

    pref[0] = suff[n+1] = 0;
    for(ll i=1 ; i<n+2 ; ++i)
    {
        if(v[i]<pref[i-1] || pref[i-1]==-1)
            pref[i] = -1;
        else
            pref[i] = v[i]-pref[i-1];
    }
    for(ll i=n ; i>=0 ; --i)
    {
        if(v[i]<suff[i+1] || suff[i+1]==-1)
            suff[i] = -1;
        else
            suff[i] = v[i]-suff[i+1];
    }

    if(pref[n]==0) return true;

    for(ll i=1 ; i<n ; ++i)
    {
        if(pref[i-1]==-1 || suff[i+2]==-1) continue;

        vector<ll> here = {pref[i-1],v[i+1],v[i],suff[i+2]};

        for(ll j=0 ; j<3 ; ++j)
        {   
            ll x = min(here[j],here[j+1]);
            here[j] -= x; here[j+1] -= x;
        }

        if(here == vector<ll>{0,0,0,0}) return true;
    }

    return false;    
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
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
} 