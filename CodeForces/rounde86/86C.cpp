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

    ll t;
    cin >> t;

    while(t--)
    {
        ll a,b,q;
        cin >> a >> b >> q;
         
        while(q--)
        {
        ll l,r,ans=0 ; cin >> l >> r;
        
        if( __gcd(a,b) == min(a,b)) 
        {
            cout << 0 << " ";
            continue;
        }

        if(b < a) swap(a,b);

        ll lcm = (a*b)/ __gcd(a,b);

        ll min_idx , max_idx , out_idx;

        if( l%lcm  == 0)
            min_idx = l / lcm;
        else
            min_idx = ( l + (lcm - l%lcm) ) / lcm;

        out_idx = min_idx - 1;

        if( r%lcm == 0 )
            max_idx = r/lcm;
        else
            max_idx = ( r + (lcm - r%lcm) ) / lcm - 1 ;
      
        if( b - (l - out_idx*lcm) > 0 )
            if( b - (l - out_idx*lcm) < r-l+1)
             ans += b - (l - out_idx*lcm);
            else
            {
                cout << 0 << " ";
                continue;
            }

        if(min_idx < max_idx) ans += (max_idx-min_idx)*b;
        
        if( max_idx >= min_idx)
        {

            if(r - max_idx*lcm +1 > b) { ans += b; }
            else
                ans += r - max_idx*lcm + 1;
        } 
        
            cout << (r-l+1) - ans << " ";
        }
        
        cout << endl; 

    }

    return 0;
} 