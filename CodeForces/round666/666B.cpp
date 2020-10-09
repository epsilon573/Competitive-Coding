// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e12;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

bool checkpow(ll idx, ll pow)
{
    ll num = 1;
    for(ll i=1 ; i<pow ; ++i)
    {
        if( maxn/num < idx )
            return false;
        else
            num *= idx;
    }
    
    return true;
}

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
    ll n,ans=0;
    cin >> n; vector<ll> v(n);
    
    for(ll i=0 ; i<n ; ++i) cin >> v[i];
        sort(v.begin(),v.end());

    if( n > 50 ){
    for(ll i=0 ; i<n ; ++i) 
    {
        ans += abs(v[i]-1);
    }
        cout << ans << endl;
    }
    else if(n==1)
    {
        cout << abs(v[0]-1) << endl;
    }
    else if(n==2)
    {
        if(v[1]<0)
        {
            cout << abs(v[0]-1)+ abs(v[1]-1) << endl;
        }
        else
        {
            cout << abs(v[0]-1) << endl;
        }
    }
    else
    {
        ans = inf;

        for(ll i=1 ; i<1e6 ; ++i)
        { 
            ll tmp=0;

            if(checkpow(i,n-1))
            {
                for(ll j=0 ; j<n ; ++j)
                    tmp += abs(bin_power(i,j) - v[j]);

                ans = min(ans,tmp);
            }
            else
                break;
        }

        cout << ans << endl;
    }

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