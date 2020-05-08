#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
 
const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
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
 
    ll t,n;
    cin >> t;
    
    vector<ll> v;    
    v.push_back(0);
 
    for(ll i=1 ; (i*(3*i+1))/2 < (ll)1e10 ; ++i )
    {
        v.pb((i*(3*i+1))/2);
    }
 
    while(t--)
    {
        cin >> n; 
 
        ll cnt = 0;
        while(n>1)
        {
            auto it = lower_bound(v.begin(),v.end(),n);
            if(*it==n)
            {
                n = 0;
            } 
            else
            {
                n = n - *prev(it);
            }
            cnt++;
        }
 
        cout << cnt << endl;
    }
 
    return 0;
} 