// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

db func(ll x, db h , db c)
{
    return ((db)x*(h+c)+h)/(db)(2*(db)x+1);
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

    while(t--)
    {
        db h,c,temp;
        cin >> h >> c >> temp;

        if( (h+c)/2 >= temp ) cout << 2 << endl;
        else
        {
            db x = (h-temp)/(2*temp - h - c);
            
            ll x1,x2; x1 = x; x2 = x1+1;

            if( abs( func(x1,h,c) - temp ) <= abs( func(x2,h,c) - temp ) )
                cout << 2*x1+1 << endl;
            else
                cout << 2*x2+1 << endl;
        }
    }

    return 0;
}