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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,k;
        cin >> n >> k;

        vector<ll> a(n),b(n);

        for(ll i=0 ; i<n ; ++i) cin >> a[i];
        for(ll i=0 ; i<n ; ++i) cin >> b[i];
      
        for(ll i=0 ; i<k ; ++i)
        {
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());

            ll hi = a[0] , bye = b[n-1];
            
            if(hi >= bye) break;

            b[n-1] = hi;
            a[0] = bye;
        }

        cout << accumulate(a.begin(),a.end(),0LL) << endl;

    }

    return 0;
} 