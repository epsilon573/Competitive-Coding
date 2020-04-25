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

    ll t;
    cin >> t;

    while(t--)
    {
        ll fwd=101 , def=101 , n ,s;
        cin >> n >> s;

        vector<ll> v(n);

        for(ll i=0 ; i<n ; ++i)
        {
            cin >> v[i];
        }

        for(ll i=0,tmp ; i<n ; ++i)
        {
            cin >> tmp;
            if(tmp) fwd = min(fwd,v[i]);
            else def = min(def,v[i]);
        }
        
        if(s + def + fwd <= 100) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
} 