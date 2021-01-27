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
    ll n,m,ans=minf;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;

    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));

    for(ll i=1 ; i<=n ; ++i)
    {
    	for(ll j=1 ; j<=m ; ++j)
    	{
 			if(a[i-1]!=b[j-1])
    			dp[i][j] = max({dp[i][j],dp[i][j-1]-1,dp[i-1][j]-1});
    		else
    			dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2);
    		
    		ans = max(ans,dp[i][j]);
    	}
    }

    cout << ans;

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