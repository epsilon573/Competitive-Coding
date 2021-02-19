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
    ll n,res=inf;
    cin >> n;
    vector<ll> v(n),ans;
    map<ll,ll> cnt;

    for(ll i=0 ; i<n ; ++i){ cin >> v[i]; cnt[v[i]]++; }

    for(auto x : cnt)
    {
        ans.pb(x.second);
    }

    sort(ans.begin(),ans.end()); 
    ll x = ans.size();
    vector<ll> suff(x),pref(x);

    pref[0] = ans[0];
    suff[x-1] = ans[x-1];

    for(ll i=1 ; i<x ; ++i) pref[i] = pref[i-1] + ans[i];
    for(ll i=x-2 ; i>=0 ; --i) suff[i] = suff[i+1] + ans[i];

    res = suff[0] - x*ans[0];

    for(ll i=1 ; i<x ; ++i)
    {
        res = min(suff[i] - (x-i)*ans[i] + pref[i-1], res);
    }
    
    cout << res << endl;
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