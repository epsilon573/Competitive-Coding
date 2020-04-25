#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 998244353;
const db eps  = 1e-9 ;
const ll maxn = 1e9+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

ll bin_power_mod(ll base, ll power, ll m) 
{
    base %= m;
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res = res * base % m;
        base = base * base % m;
        power >>= 1;
    }

    return res;
}

void solve()
{
    ll n , ans = 0 , multi = 1 , total =0;
    cin >> n;

    set<ll> s;
    map<ll,ll> cnt;

    for(ll i=0,tmp ; i<n ; ++i)
    {
        cin >> tmp;
        s.insert(tmp);
        cnt[tmp]++;
    } 

    for( ll i=1 ; i < maxn ; ++i)
    {
        if( s.find(i) != s.end() )
        {
            total += cnt[i];
            ans += (i*(( bin_power_mod( 2LL , n-total , mod)*multi)%mod))%mod;
            multi *= ( bin_power_mod( 2LL ,cnt[i] , mod)- 1) ; 

            ans%=mod , multi%=mod;
        }
        else
        {
            ans += (i*((bin_power_mod( 2LL ,n-total , mod)*multi)%mod))%mod;
            ans%=mod ;

            cout << ans << endl;
            return;
        }
    } 

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