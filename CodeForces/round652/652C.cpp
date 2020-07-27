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
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n),h(k);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];
        sort(v.begin(),v.end());
    for(ll i=0 ; i<k ; ++i) cin >> h[i];
        sort(h.begin(),h.end(), greater<ll> ());

    k -= count(h.begin(),h.end(),1);
    
    ll idx = 0,ans = 0;
 
    for(ll i=0 ; i<k ; ++i)
    {
        if(h[i]==1){
            break;
        }
        ans += v[idx];
        idx += h[i]-1;
    }
    
    for(ll i=0 ; i<k ; ++i,++idx)
    {
        ans += v[idx];

    }

    for( ; idx < n ; ++idx)
    {
        ans += 2*v[idx];
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