// Author : Epsilon573
// If it works, don't touch it.

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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;

        if( a-b <= 0 ) 
        {
            cout << b << endl;
            continue;
        }
        
        a -= b;

        ll diff = c-d;
        if( diff <= 0 ) 
        {
            cout << -1 << endl; continue;
        }
        else
        {
            ll ceil = (a + diff-1) / diff;
            cout << b+c*ceil << endl;
        }


    }

    return 0;
} 