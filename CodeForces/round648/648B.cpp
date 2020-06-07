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
    ll n;
        cin >> n;
        map<ll,vector<ll>> m;  vector<ll> v(n);

        for(ll i=0 ; i<n ; ++i) cin >> v[i];
        for(ll i=0 , tmp ; i<n ; ++i)
        {
            cin >> tmp;
            m[tmp].pb(v[i]);
        }
        

       if(m.size()>1) return true;
        
       for(auto x : m)
       {
           vector<ll> tmp = x.second;

          //  for(auto x : tmp) cerr << x << " "; cerr << endl;
           for(ll i=1 ; i<tmp.size() ; ++i)
           {
              if( tmp[i]<tmp[i-1] ) return false;
           }

        }

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
            cout << "Yes" << endl;
           else cout << "No" << endl;
    }

    return 0;
} 