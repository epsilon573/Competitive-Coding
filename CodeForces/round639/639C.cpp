#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e9;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

void solve()
{
    ll n;
    cin >> n;

    set<ll> s; ;
    for(ll i=0,tmp ; i<n ; ++i)
    {
        cin >> tmp;
        s.insert((i+tmp+maxn*n)%n); 
        // always be careful while taking mod with negative numbers
    }

    if(s.size()==n)
    {
        cout << "YES" << endl; return;
    }
    else
        cout << "NO" << endl;
    return;
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
        solve();
    }

    return 0;
} 