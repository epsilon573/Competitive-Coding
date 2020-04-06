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

    while(t--)
    {
        ll n,m,k;
        cin >> n >> m >> k;

        vector<ll> ans;

        for(ll i=1 ; i<=n ; ++i)
        {
            vector<ll> v(m+1);
            for(ll j=1,tmp ; j<=k ; ++j)
            {
                cin >> tmp;
                v[tmp]++;
            }
            auto it = max_element(v.begin(),v.end());
            ans.pb( distance(v.begin(),it) );
        }
        
        for(auto x : ans) cout << x << " ";
        cout << endl;

    }

    return 0;
} 