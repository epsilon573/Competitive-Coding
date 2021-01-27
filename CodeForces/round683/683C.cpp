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
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n,w,c,sum=0;
    cin >> n >> w;

    c = (w+1)/2;
    vector<ll> ans;
    vector<pair<ll,ll>> v;

    for(ll i=0,tmp ; i<n ; ++i)
    {
        cin >> tmp;
        v.emplace_back(tmp,i+1);
    }

    sort(v.rbegin(),v.rend());
    
    for(ll i=0 ; i<n ; ++i)
    {
        if(sum+v[i].first<c)
        {
            ans.pb(v[i].second);
            sum += v[i].first;
        }
        else if(sum+v[i].first>=c && sum+v[i].first<=w)
        {
            ans.pb(v[i].second);
            cout << ans.size() << endl;
            for(auto x : ans)
                cout << x << " "; 
            cout << endl;
            return true;
        }
    }
    
    return false;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
} 