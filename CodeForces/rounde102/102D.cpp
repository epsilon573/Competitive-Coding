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
    ll n,q,x=0;
    string s;

    cin >> n >> q >> s;
 
    vector<ll> ans(n+2,0),sum(n+2,0),pmx(n+2,minf),pmn(n+2,inf),smx(n+2,minf),smn(n+2,inf);

    for(ll i=1 ; i<n+1 ; ++i)
    {
        if(s[i-1]=='-') ans[i] = --x,sum[i]=sum[i-1]-1;
        else ans[i] = ++x,sum[i]=sum[i-1]+1;
    }

    for(ll i=1 ; i<n+1 ; ++i)
    {
        pmx[i] = max(pmx[i-1],ans[i]);
        pmn[i] = min(pmn[i-1],ans[i]);
    }
    for(ll i=n ; i>1 ; --i)
    {
        smx[i] = max(smx[i+1],ans[i]);
        smn[i] = min(smn[i+1],ans[i]);
    }

    for(ll i=0,l,r,imax,imin ; i<q ; ++i)
    {
        cin >> l >> r;
        ll isum = sum[r]-sum[l-1];

        imax = max((l!=1)*pmx[l-1],(r!=n)*(smx[r+1]-isum));
        imin = min((l!=1)*pmn[l-1],(r!=n)*(smn[r+1]-isum));
        
        cout << max(imax,0ll) + abs(min(imin,0ll)) + 1 << endl;
    }

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