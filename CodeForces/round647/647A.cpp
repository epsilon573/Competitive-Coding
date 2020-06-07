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

    ll t,a,b;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        ll ans = 0;
        
        if(a==b) {
            cout << 0 << endl;
            continue;
        }

        if(b>a)
        {
            while( (a*8) <= b ){
             a*=8; ans++;
            }
            while( (a*4) <= b ){
             a*=4; ans++;
            }
            while( (a*2) <= b ){
             a*=2; ans++;
            }

            if(a==b)
                cout << ans << endl;
            else cout << -1 << endl;
        }
        else
        {
            while( a%8==0 && a/8 >= b)
            {
                a/=8; ans++;
            }
            while( a%4==0 && a/4 >= b)
            {
                a/=4; ans++;
            }
            while( a%2==0 && a/2 >= b)
            {
                a/=2; ans++;
            }
            if(a==b)
                cout << ans << endl;
            else cout << -1 << endl;                         
        }   
    }

    return 0;
} 