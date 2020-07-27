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
    ll n; string s; cin >> n >> s;
    
    ll pref = 0 , suff = 0;
    for(ll i=0 ; i<n ; ++i)
    {
        if(s[i]=='0') pref++;
        else break;
    }
    for(ll i=n-1 ; i>=0 ; --i)
    {
        if(s[i]=='1') suff++;
        else break;
    }

    

    if(pref+suff==n) cout << s << endl;
    else{
        for(ll i=0 ; i<pref+1 ; ++i ) cout << 0;
            for(ll i=0 ; i<suff ; ++i ) cout << 1;
                cout << endl;
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