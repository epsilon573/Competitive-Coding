#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

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
        vector<ll> a(n),b(n),c(n);

        for(ll i=0 ; i<n ; ++i) cin >> a[i] >> b[i];
        
        ll tmp = a[0]-b[n-1]; 
        c[0] = max(0LL, tmp);
        for(ll i=1 ; i<n ; ++i) 
        	{ 
        		ll zz = a[i]-b[i-1] ;
        		c[i] = max(0LL , zz );
        	}

        ll sum = accumulate(c.begin(),c.end(),0LL);
        ll ans = LLONG_MAX;
        for(ll i=0 ; i<n ; ++i)
        {
        	ans = min( ans , (sum - c[i] + a[i]) );
        }

        cout << ans << endl;	
    }

    return 0;
} 