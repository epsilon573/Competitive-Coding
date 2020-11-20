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

bool solve()
{
    ll r,n;
    cin >> r >> n;
    n++;
    vector<ll> x(n),y(n),t(n),dp(n,0),mx(n,0);
    
    vector<bool> vis(n,false);
    
    vis[0] = true;
    x[0] = y[0] = 1;
    t[0] = 0;

    for(ll i=1 ; i<n ; ++i) cin >> t[i] >> x[i] >> y[i];

    for(ll i=1 ; i<n ; ++i)
    {
        for(ll j=i-1 ; j>=0 ; --j)
        {  
            ll dis = abs(x[j]-x[i]) + abs(y[j]-y[i]);
            ll tim = t[i] - t[j];
            
            if( tim >= 2*r )
            { 
                dp[i] = max(dp[i],1+mx[j]);
                vis[i] = true;
                break;
            }
          
            if(dis <= tim && vis[j])
            { 
                dp[i] = max(1 + dp[j],dp[i]);
                vis[i] = true;
            }
                
        }

        mx[i] = max(mx[i-1],dp[i]);         
    }    
    
    cout << mx[n-1] << endl;
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