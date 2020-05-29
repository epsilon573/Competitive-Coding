// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e7+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

vector<ll> v;
vector<ll> spf(maxn);

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

    ll n;
    cin >> n;
    v.resize(n);

    spf[1] = 1;
    
    for(ll i=1 ; i<maxn ; ++i) spf[i] = i;

        for(ll i = 2 ; i<maxn ; ++i)
        {
            if(spf[i] == i)
            {
                for(ll j=i*i ; j<maxn ; j+=i)
                {   
                    if( spf[j]==j ) spf[j] = i;
                }   
            }
        }
    
    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    ll curr;
    curr = v[0];
    for(ll i=1 ; i<n ; ++i) curr = __gcd(curr,v[i]);

    for(ll i=0 ; i<n ; ++i) v[i]/=curr;
    
    if(count(v.begin(),v.end(),1) == n)
    {
        cout << -1 << endl;
        return 0;
    }


    map<ll,ll> cnt;
    ll ans = 0;

    for(ll i=0 ; i<n ; ++i)
    {
        ll tmp = v[i];

        while(tmp>1)
        {
            ll div = spf[tmp];
            cnt[div]++;
            ans = max(cnt[div], ans);

            while( tmp % div == 0) tmp/=div;
        }
    }

    cout << n - ans ;

    return 0;
} 