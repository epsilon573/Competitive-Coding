// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e6+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

bool solve()
{
    ll n; cin >> n;
    vector<ll> v(n),ans(n,-1);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    set<ll> st;
    
    for(ll i=0 ; i<maxn ; ++i) st.insert(i);    

    for(ll i=0 ; i<n-1 ; ++i)
    {
        if(v[i]!=v[i+1])
        {
            ans[i+1] = v[i];
            st.erase(v[i]);
        }
    }

    st.erase(v[n-1]);

    for(ll i=0 ; i<n ; ++i)
    {
        if(ans[i]!=-1) continue;
        else
        {
            ans[i]= *st.begin();
            st.erase(st.begin());
        }
    }

    for(auto x : ans) cout << x << " ";
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

    ll t; t=1;

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