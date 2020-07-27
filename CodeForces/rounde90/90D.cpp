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

bool solve()
{
    ll n; cin >> n;
    vector<ll> v(n),o,e;

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    for(ll i=0 ; i<n ; ++i) 
    {
        if(i%2) o.pb(v[i]);
        else e.pb(v[i]);
    }    

    ll esum = accumulate(e.begin(),e.end(),0LL); // deb(esum);
    
    ll otemp = 0 , etemp = 0 , diff = 0;

    for(ll i=0; i<min(o.size(),e.size()) ; ++i)
    {
        otemp += o[i]; etemp += e[i];

        if(otemp > etemp) 
        {
           // deb(diff);
            diff = max(diff,otemp-etemp);
        }
        else otemp = etemp = 0;
    }

    e.erase(e.begin());

    otemp = etemp = 0;
    for(ll i=0; i<min(o.size(),e.size()) ; ++i)
    {
        otemp += o[i]; etemp += e[i];

        if(otemp > etemp) 
        {
           // deb(diff);
            diff = max(diff,otemp-etemp);
        }
        else otemp = etemp = 0;
    }


    cout << esum + diff << endl;

    
    return true;    
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
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this
        }
    }

    return 0;
} 