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

    ll n; string given,target;

    cin >> n;
    cin >> given >> target;

    ll ans = 0;

    for(ll i=0 ; i<n ; ++i)
    {
        ll giv = given[i] - '0';
        ll tgt = target[i] - '0';
         
        if(giv > tgt) swap(giv,tgt);
        
        ans += min(tgt-giv , giv + 10 - tgt); 
    }

    cout << ans << endl;

    return 0;
} 