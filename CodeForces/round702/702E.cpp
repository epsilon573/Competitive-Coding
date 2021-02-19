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
    ll n,cnt=0,ans=inf;
    cin >> n;
    vector<ll> dup(n),v(n),pref(n,0);

    for(ll i=0 ; i<n ; ++i){
        cin >> v[i];
        if(i) pref[i] = pref[i-1] + v[i];
        else pref[i] = v[i];
    }

    dup = v;
    sort(v.begin(),v.end());

    ll x = v[0]; ans = v[0];

    for(ll i=1 ; i<n ; ++i)
    {
        if(v[i]<=x)
        {
            x += v[i];
        }
        else if(v[i]>x)
        {
            x += v[i];
            ans = v[i];
        }
    }
    
    for(ll i=0 ; i<n ; ++i)
    {
        if(dup[i]>=ans) cnt++;
    }

    cout << cnt << endl;

    for(ll i=0 ; i<n ; ++i)
    {
        if(dup[i]>=ans) cout << i+1 << " ";
    }

    cout << endl;
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