#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
 
const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;
 
#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl
 
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n,m;
    cin >> n >> m;
 
    vector<ll> v(n);
 
    for(ll i=0 ; i<n ; ++i) cin >> v[i];
 
    ll sum = accumulate(v.begin() , v.end() , 0LL);
 
    if(sum > n) cout << -1 ;
    else cout << n-sum ; 
       
    return 0;
} 