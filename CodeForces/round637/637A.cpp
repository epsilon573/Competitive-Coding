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

    while(t--)
    {
        ll n,a,b,c,d;
        cin >> n >> a >> b >> c >> d;

        ll mx = n*(a+b), mn = n*(a-b) , pck_mn = c-d , pck_mx = c+d ;

        if( pck_mn > mx || pck_mx < mn) 
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
} 