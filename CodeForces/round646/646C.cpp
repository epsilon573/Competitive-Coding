// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e3+1;
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
        ll n,x;
        cin >> n >> x;

        vector<vector<ll>> adj(n+1);

        for(ll i=0,a,b ; i<n-1 ; ++i)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        ll need = adj[x].size();

        if(need <= 1)
        {
            cout << "Ayush" << endl; continue;
        }

        if((n-2)&1)
        {
            cout << "Ashish" << endl; continue;
        }
        else
        {
            cout << "Ayush" << endl; continue;
        }



    }

    return 0;
} 