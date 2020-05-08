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

void solve()
{
    ll n,k;
    cin >> n >> k;

    vector<char> v(n);
    string ans="";

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    sort(v.begin(),v.end());
    
    if( v[0] == v[k-1] ) 
    {
        ans += v[0];

        if( k<n && v[k] == v[n-1] )
        {
            for(ll i=0 ; i < (n-k+k-1)/k ; ++i)
            ans += v[k];
        }
        else
        {       
            for(ll i=k ; i<n ; ++i )
            ans += v[i];
        }
    }
    else
    {
        ans += v[k-1];
    }
    cout << ans << endl;
    return;


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

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
} 