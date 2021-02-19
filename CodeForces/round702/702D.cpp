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

ll n;
vector<ll> v,ans;

void recur(ll h, ll d, ll s , ll e)
{
    if(s>e) return;
    if(s==e)
    {
        ans[s] = d;
        return;
    }

    ans[h] = d;
    ll mx=-1, mxidx=-1;

    for(ll i=s ; i<h ; ++i)
    {
        if(v[i]>mx)
        {
            mx = v[i];
            mxidx = i;
        }
    }

    if(s!=h)
        recur(mxidx,d+1,s,h-1);

    mx=-1, mxidx=-1;
    for(ll i=h+1 ; i<=e ; ++i)
    {
        if(v[i]>mx)
        {
            mx = v[i];
            mxidx = i;
        }
    }

    if(h!=e)
        recur(mxidx,d+1,h+1,e);

    return;
}

bool solve()
{
    cin >> n;
    v.resize(n); 
    ans.resize(n);

    ll idx;

    for(ll i=0 ; i<n ; ++i)
    {
        cin >> v[i];
        if(v[i]==n) idx = i;
    }

    recur(idx,0,0,n-1);

    for(auto x : ans) cout << x << " ";

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