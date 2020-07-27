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
    string s; cin >> s; vector<pair<ll,ll>> dp;
    ll cur = 0;

    for(ll i=0 ; i<s.size() ; ++i)
    {
        if(s[i]=='-') --cur;
        else ++cur;

        if(cur<0) dp.emplace_back(abs(cur),i+1);
    }

    if(dp.size()==0) cout << s.size() << endl;
    else
    {
        ll maxi = dp[0].first;
        
        for(ll i=1 ; i<dp.size() ; ++i)
        {
            dp[i].first -= maxi;

            maxi = max(dp[i].first+maxi,maxi); 
        }
        
        ll ans = 0;
        for(ll i=0 ; i<dp.size() ; ++i)
        {
            if(dp[i].first>0)
                ans += dp[i].first*dp[i].second;
        }

        cout << ans + s.size() << endl;

    }


    
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