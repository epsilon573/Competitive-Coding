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

    ll t;
    cin >> t;

    for(ll easy=1 ; easy<=t ; ++easy)
    {
        cout << "Case #" << easy << ":" << endl;
        ll n;
        cin >> n;

        vector<ll> rows; 

        if(n<=30)
        {
            for(ll i=1 ; i<=n ; ++i)
                cout << i << " " << i << endl;
        }
        else
        {
            n = n-30;
            ll bit_length = log2(n) + 1;
            ll extra = 30 - (bit_length - __builtin_popcount(n)) ;
            
            ll left = 1;

            for(ll i=0 ; i<=bit_length ; ++i)
            {
                if( (n >> i)&1 ) rows.pb(i+1);
            }
            
            for(ll row=1 ; row<=rows[rows.size()-1]+extra ; ++row)
            {
                if( count(rows.begin() , rows.end() , row) )
                {
                    if(left)
                    
                        for(ll j=1 ; j<=row ; ++j)
                            cout << row << " " << j << endl;
                    
                    else
                    
                        for(ll j=row ; j>=1 ; --j)
                            cout << row << " " << j << endl;
                    

                    left ^= 1;
                }

                else 
                {
                    if(left)
                    
                        cout << row << " " << 1 << endl;
                    
                    else

                        cout << row << " " << row << endl;
                }    
            }

        }

    
    }

    return 0;
} 