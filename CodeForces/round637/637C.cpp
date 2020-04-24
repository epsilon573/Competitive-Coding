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

void solve()
{
        ll n;
        cin >> n;
        
        vector<ll> v(n);
        for(ll i=0 ; i<n ; ++i) cin >> v[i]; 

        for(ll i=0 ; i<n ; ++i)
        {
            ll start = i;
            while( v[i+1] == v[i]+1 )
            {
                ++i;
            }
 
            sort(v.begin()+start,v.begin()+i+1,greater<ll> ());        
        } 

        
        ll i=1;
        for(auto it = v.end()-1 ; it>= v.begin() ; it--,i++)
        {
             if(*it!=i) 
             {
                cout << "No" << endl;
                return;
             }
        }
        cout << "Yes" << endl;
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