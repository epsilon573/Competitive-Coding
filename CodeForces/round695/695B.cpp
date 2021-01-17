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
    ll n,cnt=0,ans=inf;
    cin >> n;
    vector<ll> v(n),pref(n,0),suff(n,0);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    for(ll i=1 ; i<n-1 ; ++i)
    {
        if(v[i]>v[i+1] && v[i]>v[i-1]) cnt++;
        if(v[i]<v[i+1] && v[i]<v[i-1]) cnt++;

        pref[i] = cnt;
    }

    cnt = 0;
    for(ll i=n-2 ; i>0 ; --i)
    {
        if(v[i]>v[i+1] && v[i]>v[i-1]) cnt++;
        if(v[i]<v[i+1] && v[i]<v[i-1]) cnt++;

        suff[i] = cnt;
    }

    suff[0] = pref[n-1] = cnt;

    for(ll i=0,tmp=0 ; i<n-1 ; ++i)
    {
        ll rem = v[i];
        v[i] = v[i+1],tmp=0;

            for(ll j = i-5 ; j<=i+5 ; ++j)
            {
                if(j<1 || j>n-2) continue;

                if(v[j]>v[j+1] && v[j]>v[j-1]) tmp++;
                if(v[j]<v[j+1] && v[j]<v[j-1]) tmp++;
            }

        ll left=0,right=0;
        if(i-6>=0)
        {
            left = pref[i-6];
        }
        if(i+6<n)
        {
            right = suff[i+6];
        }

        ans = min(ans,tmp+left+right);

        v[i] = rem;
    }

    for(ll i=0,tmp=0 ; i<n-1 ; ++i)
    {
        ll rem = v[i];
        v[i] = v[i-1],tmp=0;

            for(ll j = i-5 ; j<=i+5 ; ++j)
            {
                if(j<1 || j>n-2) continue;

                if(v[j]>v[j+1] && v[j]>v[j-1]) tmp++;
                if(v[j]<v[j+1] && v[j]<v[j-1]) tmp++;
            }

        ll left=0,right=0;
        if(i-6>=0)
        {
            left = pref[i-6];
        }
        if(i+6<n)
        {
            right = suff[i+6];
        }

        ans = min(ans,tmp+left+right);
        v[i] = rem;
    }
    for(ll i=0,tmp=0 ; i<n-1 ; ++i)
    {
        ll rem = v[i];
        v[i] = inf,tmp=0;

            for(ll j = i-5 ; j<=i+5 ; ++j)
            {
                if(j<1 || j>n-2) continue;

                if(v[j]>v[j+1] && v[j]>v[j-1]) tmp++;
                if(v[j]<v[j+1] && v[j]<v[j-1]) tmp++;
            }

        ll left=0,right=0;
        if(i-6>=0)
        {
            left = pref[i-6];
        }
        if(i+6<n)
        {
            right = suff[i+6];
        }

        ans = min(ans,tmp+left+right);

        v[i] = rem;
    }

    for(ll i=0,tmp=0 ; i<n-1 ; ++i)
    {
        ll rem = v[i];
        v[i] = minf,tmp=0;

            for(ll j = i-5 ; j<=i+5 ; ++j)
            {
                if(j<1 || j>n-2) continue;

                if(v[j]>v[j+1] && v[j]>v[j-1]) tmp++;
                if(v[j]<v[j+1] && v[j]<v[j-1]) tmp++;
            }

        ll left=0,right=0;
        if(i-6>=0)
        {
            left = pref[i-6];
        }
        if(i+6<n)
        {
            right = suff[i+6];
        }

        ans = min(ans,tmp+left+right);
        v[i] = rem;
    }
    cout << min(ans,cnt) << endl;
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