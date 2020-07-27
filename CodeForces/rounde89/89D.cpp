// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e7+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

bool solve()
{
    vector<vector<ll>> factors(maxn); vector<ll> spf(maxn),spl;
    ll n; cin >> n;
    vector<pair<ll,ll>> ans;

    for(ll i=1 ; i<maxn ; ++i) spf[i] = i;

    for(ll i=2 ; i*i<maxn ; ++i)
    {
        if(spf[i]==i)
            for(ll j=i*i ; j<maxn ; j+=i)
            {
                if(spf[j]==j)
                    spf[j] = i;
            }
    }    

    for(ll i=0; i<n ; ++i)
    {
        ll num; cin >> num;
    
        set<ll> div; ll tmp = num; 

        while(tmp > 1)
        {
            div.insert(spf[tmp]); tmp/=spf[tmp];
        }

        if(div.size()==1) ans.eb(-1,-1);
        else
        {
            ll x = *div.begin();
            while(num%x==0) num/=x;
            ans.eb(x,num);
        }
    }

    for(auto x : ans) cout << x.first << " "; cout << endl; 
    for(auto x : ans) cout << x.second << " "; cout << endl;    
    
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

    ll t=1;

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