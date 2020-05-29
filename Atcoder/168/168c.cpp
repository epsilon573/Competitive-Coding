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
#define pi  3.141592653589793
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

    ll a,b,h,m;
    cin >> a >> b >> h >> m;
    
    db angle;

    angle = 2*pi*abs( (db)m/60 - (db)h/12 - ((db)m/60)/(db)12  );

    cout << setprecision(12) << fixed << sqrt(a*a+b*b-2*a*b*cos(angle)); 
    return 0;
}
