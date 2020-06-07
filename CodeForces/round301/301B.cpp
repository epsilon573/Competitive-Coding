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

    ll n,k,p,x,y;
    cin >> n >> k >> p >> x >> y;

    ll req = (n-1)/2;
    ll cnt = 0 , fill = n-k , sum = 0, ones = 0;
    vector<ll> v(k);

    for(ll i=0 ; i<k ; ++i){
     
     cin >> v[i];
     sum += v[i];

     if(v[i]<y) cnt++;

    }

    if(cnt > req) 
    {
        cout << -1 << endl;
        return 0;
    }
    
    // deb(req); deb(cnt);

    if( req - cnt > fill )
    {
       ones = fill;
       fill = 0;
    }
    else
    {
       ones = (req-cnt);
       fill -= (req-cnt); 
    }

    if( sum + ones + fill*y > x) cout << -1 << endl;
    else
    {
        for(ll i=0 ; i<ones ; ++i ) cout << 1 << " ";
            for(ll i=0 ; i<fill ; ++i) cout << y << " ";
    }

    return 0;
} 