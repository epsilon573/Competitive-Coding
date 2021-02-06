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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n),p(m),ans;
    vector<ll> cntp(n+1);
    
    map<ll,vector<ll>> to_change;
    vector<ll> spare(n+1,-1);

    set<ll> s;

    for(ll i=0 ; i<n ; ++i) cin >> a[i]; 
    for(ll i=0 ; i<n ; ++i) { 
        cin >> b[i]; 
        if(a[i]!=b[i])                            
            to_change[b[i]].pb(i+1);
        else
            spare[b[i]] = i+1;
    }

    for(ll i=0 ; i<m ; ++i){ 
        cin >> p[i];

        if(spare[p[i]]!=-1 || to_change.find(p[i]) != to_change.end())
        s.insert(p[i]);
         
        cntp[p[i]]++; 
    }

    for(ll i=0 ; i<m ; ++i)
    {
        if(to_change.find(p[i]) == to_change.end() && spare[p[i]]==-1)
        {
            if(to_change.size()!=0)
            {
                ans.pb((to_change.begin())->second[0]);
                
            }
            else
            {
                if(s.size()==0) return false;
                else
                {
                    ll color = *s.begin();
                    to_change[color].pb(spare[color]);
                    ans.pb(spare[color]);
                }
            }
        }
        else if(to_change.find(p[i]) == to_change.end())
        {
            ans.pb(spare[p[i]]);
        }
        else
        {
            ans.pb((to_change[p[i]])[0]);
            spare[p[i]] = to_change[p[i]][0];

            if(to_change[p[i]].size()==1)
                to_change.erase(p[i]);
            else
                to_change[p[i]].erase(to_change[p[i]].begin());
        }

        cntp[p[i]]--;
        if(cntp[p[i]]==0) s.erase(p[i]);
    }

    if(to_change.size()!=0) 
        return false;

    cout << "YES" << endl;
    for(auto x : ans) cout << x << " ";  cout << endl;
    return true;    
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
            //;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
} 