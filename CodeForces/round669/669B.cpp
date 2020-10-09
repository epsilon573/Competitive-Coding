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
    ll n;
    cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];
    
    auto x = max_element(v.begin(),v.end());

    vector<ll> ans(n);

    ll gcd = *x; ll idx = 0;
    map<ll,ll> vis;
    
    for(ll i=0 ; i<n ; ++i) vis[i] = 0;

    for(ll i=0 ; i<n ; ++i)
    {
       ll tmp = 1;
       for(ll j=0 ; j<n ; ++j)
       {
           if(!vis[j])
           if( __gcd(gcd,v[j]) >= tmp )
           {
                tmp = __gcd(gcd,v[j]);
                idx = j;
           }
       }
        
       gcd = tmp; 
       ans[i] = v[idx];
       vis[idx] = 1;
    }

    for(ll i=0 ; i<n ; ++i)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

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