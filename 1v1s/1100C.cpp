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
#define pi acos(-1)

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

    db n,R;
    cin >> n >> R;
    

    cout << setprecision(10) << fixed ;
    cout << ( (db)R*sin(pi/(db)n) )/ ((db)1 - (db)sin(pi/((db)n)));

    // 2Rsin(pi/2*n)/ (1-2sin(pi/2*n)) = r
    return 0;
} 
