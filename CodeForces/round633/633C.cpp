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

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t,n;
    cin >> t;

    while(t--)
    {
       cin >> n;
       vector<ll> v(n);
       for(ll i=0 ; i<n ; ++i) cin >> v[i];

       ll max_so_far = LLONG_MIN , diff_so_far = 0;
       for(auto x : v) 
        { 
            if(x >= max_so_far)
            {
                max_so_far = x;
            }
            else
            {
                diff_so_far = max( max_so_far - x , diff_so_far ); 
            }
        }
        
        if(diff_so_far)
        cout << (ll)log2(diff_so_far) + 1 << endl;
        else
        cout << 0 << endl;


    }

    return 0;
} 