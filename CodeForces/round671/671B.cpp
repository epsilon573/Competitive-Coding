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

ll bin_power(ll base, ll power) 
{
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

bool solve()
{
    ll n,cnt=0;
    cin >> n;
    
    for(ll i=1 ; i<=60 && n>0 ; ++i,++cnt)
    {
        ll x = bin_power(2,i) - 1;

        if( x<=1e10 ) 
        {    
            n -= (x*(x+1))/2;
            if(n<0) break;
        }
        else break;
    }

    cout << cnt << endl;
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