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
    ll n,m;
    string a,b,ans1="",ans2="";

    cin >> a >> b;
    n = a.size(), m = b.size();
    
    ll x = (n*m)/(__gcd(n,m));

    for(ll i=0 ; i<x ; ++i)
    {
        ans1 += a[i%n];
        ans2 += b[i%m];
    }

    if(ans1!=ans2)
        cout << -1 << endl;
    else
        cout << ans1 << endl;

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