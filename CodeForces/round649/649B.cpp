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
    ll n; cin >> n;
    vector<ll> v(n),ans;

    for(ll i=0 ; i<n ; ++i) cin >> v[i];
    
    bool inc = false, dec = false; 
    ans.pb(v[0]);

    if(v[1]>v[0]) inc = true;
    else dec = true;

    for(ll i=1 ; i<n-1 ; ++i)
    {
        if(v[i+1]<v[i] && inc == true)
        {
            dec = true;
            inc = false;
            ans.pb(v[i]);
        }
        else if(v[i+1]>v[i] && dec == true)
        {
            dec = false;
            inc = true;
            ans.pb(v[i]);
        }        
    } 

    ans.pb(v[n-1]);
    
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl; 
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

    ll t;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this
        }
    }

    return 0;
} 