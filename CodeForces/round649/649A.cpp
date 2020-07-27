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
    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    ll cnt = 0 , sum = 0 , l=n , r=n;

    for(ll i=0 ; i<n ; ++i)
    {
        if(v[i]%x==0) cnt++;
        sum += v[i];
    }

    if(cnt==n) 
    {
        return false;
    }
    if(sum%x!=0)
    {
        cout << n << endl;
        return true;
    }

    for(ll i=0 ; i<n ; ++i)
    {
        if(v[i]%x!=0) 
        {
            l = min(l,i+1);
            r = min(r ,n-i);
        }
    }

    cout << n - min(l,r) << endl;    
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
            cout << -1 << endl;
        }
    }

    return 0;
} 