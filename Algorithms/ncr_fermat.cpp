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

ll fac[1007];

void comp()
{
    fac[0] = 1; 
    
    for (ll i = 1; i <= 1005; i++) 
        fac[i] = (fac[i - 1] * i) % mod; 
}


ll power(ll x, ll y, ll p = mod) 
{ 
    ll res = 1; 

    x = x % p; 
  
    while (y > 0) { 

        if (y & 1) 
            res = (res * x) % p; 
   
        y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 


ll modInverse(ll n, ll p = mod) 
{ 
    return power(n, p - 2, p); 
} 
  

ll NCR(ll n, ll r, ll p=mod) 
{ 
    if( n <= r) return 0;

    if (r == 0) 
        return 1; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
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