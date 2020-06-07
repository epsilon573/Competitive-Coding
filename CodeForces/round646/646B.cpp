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
        string s;
        cin >> s; ll n = s.size();

        vector<ll> zero(n+1,0),one(n+1,0);

        for(ll i=0 ; i<n ; ++i)
        {
            if(s[i]=='1')
            {
                one[i+1] = one[i]+1;
                zero[i+1] = zero[i];
            }
             if(s[i]=='0')
            {
                one[i+1] = one[i];
                zero[i+1] = zero[i]+1;
            }
        }
        
        ll ans = n;

        for(ll i=0 ; i<n ; ++i)
        {
           ans = min(ans,  zero[n] - zero[i] + one[i]);
           ans = min( ans, one[n]- one[i] + zero[i]);
        }

        cout << ans << endl;
    }

    return 0;
} 