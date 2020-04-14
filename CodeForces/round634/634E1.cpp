#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2001;
const ll inf = LLONG_MAX;

ll cnt[27][2001];

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
        memset(cnt , 0 , sizeof(cnt));
        ll n;
        cin >> n;
        vector<ll> v(n+1);

        for(ll i=1 ; i<=n ; ++i) cin >> v[i];

        for(ll i=1 ; i<=26 ; ++i) 
        {
            for(ll j=1 ; j<=n ; ++j)
            {
                if(v[j] == i)
                    cnt[i][j] = cnt[i][j-1] + 1;
                else
                    cnt[i][j] = cnt[i][j-1];
            }
        }
        
        ll ans = 0;
        for(ll i=1 ; i<=n ; ++i)
        {
            for(ll j=i ; j<=n ; ++j)
            {
                ll center_max = 0 , side_max = 0;
                for(ll k=1 ; k<=26 ; ++k)
                {
                    center_max = max(center_max , cnt[k][j]-cnt[k][i-1]);
                    side_max = max(side_max , 2*min(cnt[k][i-1],cnt[k][n] - cnt[k][j]));
                }
                
                ans = max(ans, center_max+side_max);
            }
        }    

        cout << ans << endl;
    }

    return 0;
} 