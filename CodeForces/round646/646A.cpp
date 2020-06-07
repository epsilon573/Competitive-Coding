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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,x,odd=0,even=0;
        cin >> n >> x;
        

        for(ll i=0,tmp ; i<n ; ++i) 
        {
            cin >> tmp;
            if(tmp&1) odd++;
            else even++;
        } //deb(odd); deb(even);

        if( odd==0 )
        {
            cout << "No" << endl;
            continue;
        }
        else
        {
            if(odd&1) {

                if( !(x&1) && odd >= x)
                    x = 1;
                else
                    x -= odd;

            }
            else 
            {
                if( !(x&1) && odd-1 >= x)
                    x = 1;
                else
                    x -= odd-1;
            }
            
            x -= even;

            if(x <= 0)
            {
              cout << "Yes" << endl;
              continue;
            }
            else
            {
              cout << "No" << endl;
              continue;
            }                

        }
    }

    return 0;
} 