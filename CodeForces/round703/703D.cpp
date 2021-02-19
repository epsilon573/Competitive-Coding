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

ll n,k;
vector<ll> v(n);

bool check(ll mid)
{
    vector<ll> pref(n,inf),here(n),sum(n);

    for(ll i=0 ; i<n ; ++i)
    {
        if(v[i]>=mid) here[i]=1;
        else here[i]=-1;

        if(i) sum[i] = sum[i-1]+here[i];
        else sum[i] = here[i];

        if(i) pref[i] = min(pref[i-1],sum[i]);
        else pref[i] = sum[i];
    }

    for(ll i=0 ; i<n ; ++i)
    {
        ll target = sum[i]-1, low = 0 , high = i, x , ans=-1;

        while(low<=high)
        {
            x = (low+high)/2;

            if(pref[x]>target)
            {
                low = x+1;
            }
            else
            {
                ans = x;
                high = x-1;
            }
        }

        if( 0<=target && i>=k-1 )
        {
            return true;
        }

        if(ans!=-1 && i-ans>=k)
        {
            return true;
        }
    }

    return false;
}

bool solve()
{
    cin >> n >> k;
    v.resize(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    ll low = 1, high = n+1 , mid, ans = -1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(check(mid))
        {
            low = mid+1;
        }
        else 
        {
            ans = mid;
            high = mid-1;
        }
    }
    
    cout << ans-1 << endl;
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