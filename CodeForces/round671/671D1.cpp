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
    ll n;
    cin >> n;
    vector<ll> v(n),ans(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];
        sort(v.rbegin(),v.rend());
    
    ll cnt = 0 ;

    if(n&1)
    cout << n/2 << endl;
    else
        cout << n/2 - 1 << endl;
    for(ll i=0 ; i<n ; i+=2,cnt++)
        ans[i] = v[cnt];

    for(ll i=1 ; i<n ; i+=2,cnt++)
         ans[i] = v[cnt];

    for(auto x:ans) cout << x << " ";
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

    ll t=1;
  //  cin >> t;

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