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
#define deb(x) cerr << #x << " " << x << endl

string ans = "";


void solve()
{
    ans = "";
    ll x,y;

    cin >> x >> y;

    if( !((x+y)&1) )
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    else
    {
        while( abs(x) + abs(y) > 1)
        {
            if(x&1)
            {
                y /= 2;

                ll a = (x+1)/2;
                ll b = (x-1)/2;

                if( (a+y)&1 ) 
                {
                    x = a;
                    ans += "W";
                }

                if( (b+y)&1 ) 
                {
                    x = b;
                    ans += "E";
                }

            }

            else
            {
                x /= 2;

                ll a = (y+1)/2;
                ll b = (y-1)/2;

                if( (a+x)&1 ) 
                {
                    y = a;
                    ans += "S";
                }

                if( (b+x)&1 ) 
                {
                    y = b;
                    ans += "N";
                }
            }    
        }
    }
    
    if( !y )
    {
        if(x==1) ans += "E";
        if(x==-1) ans += "W";
    } 
    if( !x )
    {
        if(y==1) ans += "N";
        if(y==-1) ans += "S";
    }

    cout << ans << endl;
    return; 
}

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

    for(ll z = 1 ; z<=t ; ++z)
    {
        cout << "Case #" << z << ": " ;
        solve();
    }

    return 0;
} 