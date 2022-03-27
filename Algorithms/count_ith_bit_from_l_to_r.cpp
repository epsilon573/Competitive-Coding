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
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

ll cnt_bits(ll l, ll r, ll bit)
{
    ll res = 0;
    ll div = 1ll<<(bit+1);

    ll remL = (div - l%div)%div, remR = r%div + 1ll;
    ll ceilL = (l+div-1)/div, floorR = r/div;

    res += (floorR - ceilL)*(1ll<<bit);
    res += remR - min(remR, 1ll<<bit);
    res += min(remL, 1ll<<bit);

    return res;
}

bool solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    
    
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
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 