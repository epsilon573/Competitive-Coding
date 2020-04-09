#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

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

    srand(time(0));

    while(t--)
    {
        ll n,m,k;
        cin >> n >> m >> k;

        vector<ll> ans; 
        vector<ll> exm[n+1];

        for(ll i=1 ; i<=n ; ++i)
        {
            for(ll j=1,tmp ; j<=k ; ++j)
            {
                cin >> tmp;
                exm[i].pb(tmp);
            }
        }
        
        ll max = INT_MIN;

        for(ll i=1 ; i<=300 ; ++i)
        {
            vector<ll> tmpans; 
            for(ll j=1 ; j<=n ; ++j)
            {
                tmpans.pb( exm[j][rand()%k] );
            }

            ll min_score = INT_MAX;

            for(ll x=1 ; x<=k ; ++x)
            {
                ll score=0;
                for(ll y=1 ; y<=n ; ++y)
                {
                    if(tmpans[y-1] == exm[y][x-1]) score++;
                }
                min_score = min(score,min_score);
            }

            if(min_score > max) 
            {
                max = min_score;
                ans.clear();
                ans = tmpans;
            }

        }
        
        for(auto x : ans) cout << x << " ";
        cout << endl;

    }

    return 0;
} 