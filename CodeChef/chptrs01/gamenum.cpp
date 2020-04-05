#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

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
    	ll a,b;
        cin >> a >> b;
        ll length;

        length = max(log2(b)+1 , log2(a)+1);

        ll ans = a^b , ans_idx = 0;
        for(ll i=0 ; i<length ; ++i)
        {
        	ll last_bit = b&1;
        	b >>= 1 ;
        	b |= ( last_bit << (length-1) );

        	if( (a^b) > ans) { ans = a^b; ans_idx = i+1; }
        }

        cout << ans_idx << " " << ans << endl; 
    }

    return 0;
} 