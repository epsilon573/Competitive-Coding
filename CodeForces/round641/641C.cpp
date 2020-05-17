#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e5+1;

// Read constraints carefully dumbass!!

const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

ll bin_power(ll base, ll power) 
{
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

ll spf[maxn];

vector<set<ll>> vs(maxn);
vector<vector<ll>> cnt(maxn);
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


    for(ll i=0 ; i<maxn ; ++i) spf[i] = i;
    
        for(ll i = 2 ; i<200001 ; ++i)
        {
            if(spf[i]==i)
            {
                for(ll j=i*i ; j<200001 ; j+=i)
                {   
                    if(spf[j] == j) spf[j] = i;
                }   
            }
        }

        ll n;
        cin >> n;
        vector<ll> v(n+1);
        for(ll i=1 ; i<=n ; ++i) cin >> v[i];
         
        for(ll i=1 ; i<=n ; ++i)
        {
            ll tmp = v[i];
            while( tmp > 1)
            {
                ll fac = spf[tmp];
               // cerr << tmp << " " << fac << endl;
                vs[fac].insert(i);
                
                ll hi = 0;

                while( tmp%fac == 0 ){
                //   cerr << tmp << endl;
                   tmp /= fac;
                   hi++;
                }
                
                // cerr << tmp << " " << fac << " -> " << hi << endl;
                cnt[fac].pb(hi);
            }
        }
        
        ll ans = 1;
        for(ll i=2 ; i< maxn ; ++i) sort(cnt[i].begin(),cnt[i].end());
        for(ll i=2 ; i< maxn ; ++i)
        {
            if(spf[i]==i)
            {
                if( vs[i].size() == n )
                {
                    ans *= bin_power(i,cnt[i][1]);
                }
 
                else if( vs[i].size() == n-1 )
                {
                    ans *= bin_power(i,cnt[i][0]);
                }

            }


        }

        cout << ans << endl;   
    return 0;
} 