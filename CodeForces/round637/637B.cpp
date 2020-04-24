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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,k;
        cin >> n >> k;

        vector<ll> v(n);
        for(ll i=0 ; i<n ; ++i) cin >> v[i];


        ll peaks = 0 , idx = 0 ;

        for(ll i=1 ; i<k-1 ; ++i)
        {
            if( v[i] > v[i-1] && v[i] > v[i+1]) peaks++;
        }

        ll mx = peaks;
        
        for(ll i=1 ; i+(k-1) < n ; ++i)
        {
            if( v[i] > v[i-1] && v[i] > v[i+1] ) peaks--;
            if( v[i+k-2] > v[i+k-2-1] && v[i+k-2] > v[i+k-2+1] ) peaks++;
            
            if(peaks > mx)
            {
                idx = i;
                mx = peaks;
            }

        }

        cout << mx+1 << " "<< idx+1 << endl;

    }

    return 0;
} 