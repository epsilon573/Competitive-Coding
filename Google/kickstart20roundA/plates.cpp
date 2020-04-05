#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

ll dp[51][1501];
ll sum[1000][1000];

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

    ll t,n,k,p;
    cin >> t;

    for(ll z=1 ; z<=t ; ++z)
    {
    	cout << "Case #" << z <<": ";
    	cin >> n >> k >> p;
      
        for(ll i=0 ; i<=n ; ++i) sum[i][0] = 0;

        for(ll i=0 ; i<n ; ++i)
        {
        	for(ll j=0,tmp ; j<k ; ++j)
        	{
        		cin >> tmp; 
        		sum[i+1][j+1] = tmp + sum[i+1][j];
        	}
        }
        
        for(ll i=0 ; i <= min(k,p) ; ++i) dp[1][i] = sum[1][i];
        	
        for(ll i=2 ; i<=n ; ++i) 
        	for(ll j=1 ; j<=p ; ++j)
        	{
        		dp[i][j] = dp[i-1][j];
        		for( ll y=1 ; y <= k && y <= j  ; ++y)
        		{	
        			dp[i][j] = max(dp[i][j], sum[i][y] + dp[i-1][j-y]);
        		}
        	}

        cout << dp[n][p] << endl; 


    }

    return 0;
} 