#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<ll> dp(n+1),v(n+1);
        for(ll i=1 ; i<=n ; ++i) cin >> v[i];

        for(ll i=1 ; i<=n ; ++i) dp[i] = 1;     

        for(ll i=1 ; i<=n ; ++i)
        {
            for(ll j=2 ; i*j <= n ; ++j)
            {
                if( v[i*j] > v[i] )
                    dp[i*j] = max( dp[i*j], dp[i]+1);
            }
        } 

        cout << *max_element(dp.begin(),dp.end()) << endl;   
    }

    return 0;
} 