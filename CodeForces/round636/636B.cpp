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

    ll t,n;
    cin >> t;

    while(t--)
    {
        ll cnt =0;
        cin >> n;
        n /= 2;
        vector<ll> odds,evens;

        if(n&1) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;

            for(ll i=3 ; ; i+=8)
            {
                evens.pb(i-1); evens.pb(i+1);
                odds.pb(i-2); odds.pb(i+2);

                cnt += 2;
                if(cnt == n) break;
            }
            
            for(auto x : evens) cout << x << " ";
                for(auto x : odds) cout << x << " ";
                    cout << endl;
        }
    }

    return 0;
} 