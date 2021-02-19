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
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n),sum(n,0),pref(n,-1);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    for(ll i=0 ; i<n ; ++i)
    {
        if(!i) sum[i] = v[i];
        else sum[i] = sum[i-1]+v[i];
    }

    for(ll i=0 ; i<n ; ++i)
    {
        if(!i) pref[i] = sum[i];
        else pref[i] = max(pref[i-1],sum[i]);
    }

    while(k--)
    {
        ll x,cyc; 
        cin >> x;

        if(sum[n-1]<=0)
        {
            cyc = 0;
        }
        else
        {
            cyc = max(0ll, (x-pref[n-1]+sum[n-1]-1)/sum[n-1] );
            x -= cyc*sum[n-1];
        }

        ll low=0 , high=n-1, mid, ans=-1;

        while(low<=high)
        {
            mid = (low+high)/2;

            if(pref[mid]>=x)
            {
                ans = mid; 
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        cout << ans + cyc*n << " ";
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