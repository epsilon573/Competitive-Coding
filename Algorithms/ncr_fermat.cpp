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

ll fac[maxn],invfact[maxn];

ll power(ll x, ll y) 
{ 
    ll res = 1; 
    x = x % mod; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % mod; 
        y = y >> 1; 
        x = (x * x) % mod; 
    } 

    return res; 
} 

ll modInverse(ll n) 
{ 
    return power(n, mod - 2); 
} 
  
void comp()
{
    fac[0] = 1, invfact[0] = 1; 
    
    for (ll i = 1; i < maxn; i++){ 
        fac[i] = (fac[i - 1] * i) % mod;
        invfact[i] = modInverse(fac[i]);
    } 
}

ll NCR(ll n, ll r, ll p=mod) 
{
    if(r < 0 || n < 0)
        assert(false);

    if( n < r ) return 0;

    if (r == 0 || r == n) 
        return 1; 
    
    return ( fac[n] * invfact[r]  % mod) * invfact[n - r] % mod;  
}

bool solve()
{
    // solve here
    
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