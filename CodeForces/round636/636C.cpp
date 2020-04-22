#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

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
        ll flag = 0 , ans = 0 , mx = 0 ;
        cin >> n;

        vector<ll> v(n);
        for(ll i=0 ; i<n ; ++i) cin >> v[i];

        for(ll i=0 ; i<n ; ++i)
        {
            ll mx = LLONG_MAX;
            while( v[i]<0 && i<n )
            {
                mx = min(abs(v[i]),mx);
                ++i;
            }
            if(mx!=LLONG_MAX)
            ans -= mx;
        }
        
        for(ll i=0 ; i<n ; ++i)
        {
            ll mn = 0;

            while(v[i]>0 && i<n)
            {
                mn = max(v[i],mn);
                ++i;
            }
            
            ans += mn;
        }

        cout << ans << endl;  
    }

    return 0;
} 