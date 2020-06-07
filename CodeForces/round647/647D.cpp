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
    ll n,m;
    cin >> n >> m;
     
    vector<ll> ans(n+1),output;
    vector<vector<ll>> adj(n+1);
    vector<pair<ll,ll>> topic;
 
    for(ll i=0,x,y ; i<m ; ++i)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(ll i=0,tmp ; i<n ; ++i)
    {
       cin >> tmp;
       topic.emplace_back(tmp,i+1);

    }

    sort(topic.begin(),topic.end());

    /* for(auto x : topic)
    {
        cerr << x.first << " " << x.second << endl;
    } */

    for(ll i=0 ; i<n ; ++i)
    {
        ll idx = topic[i].second;
        ll num = topic[i].first;
    
        set<ll> cnt;

        for(auto x : adj[idx])
        {
            if(ans[x] == num)
                return false;
            else
                if(ans[x]) cnt.insert(ans[x]);
        }

        if( cnt.size()!= num-1) return false;

        ans[idx] = num;
        output.pb(idx);
    }

    for(auto x : output) cout << x << " " ;
    cout << endl;

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

 
        if(!solve())
        {
            cout << -1 << endl;
        }

    return 0;
} 