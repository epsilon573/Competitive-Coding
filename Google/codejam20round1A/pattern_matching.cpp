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

    ll t;
    cin >> t;

    for(ll easy=1 ; easy<=t ; ++easy)
    {
        cout << "Case #" << easy << ": ";
        ll n;
        string pref = "" , suff = "" , ans = "" ;
        cin >> n;
        vector<ll> prefix(n),suffix(n);
        vector<string> v(n); 

        for(ll i=0 ; i<n ; ++i)
        {
            cin >> v[i];
        }

        for(ll i= 0 ; i<n ; ++i)
        {
            ll x = v[i].find_first_of("*",0);
            prefix[i] = x;
            if( x > pref.size() )
            {
                pref = v[i].substr(0,x);
            }
            
            ll y = v[i].find_last_of("*");
            ll z = v[i].size() - 1 - y;
            suffix[i] = z; 
            if( z > suff.size() )
            {
                suff = v[i].substr( y+1 , z );
                reverse(suff.begin() , suff.end());
            }
        }
        
        cerr << pref << " " << suff << endl;

        ll flag = 1 ;

        for(ll i=0 ; i<n && flag ; ++i)
        {
            for(ll j=0 ; j < prefix[i] ; ++j )
            {
                if( pref[j] != v[i][j] )
                    flag = 0;
            }

            for(ll j=0,k=v[i].size()-1 ; j<suffix[i] ; ++j,--k)
            {
                if( suff[j] != v[i][k] )
                    flag = 0; 
            }
        }
        
        if(flag)
        {
            ans += pref;
            for(ll i=0 ; i<n ; ++i)
            {
                for(ll j=prefix[i] ; j<=v[i].size()-1-suffix[i] ; ++j )
                {
                    if( v[i][j] != '*' )
                        ans +=  v[i][j];
                }
            }
            reverse(suff.begin(),suff.end());
            ans += suff;
        }
        else
            ans = "*";

        cout << ans << endl;

    }

    return 0;
} 