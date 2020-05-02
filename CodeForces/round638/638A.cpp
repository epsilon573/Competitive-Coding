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
        ll n;
        cin >> n;

        ll pile1 = 0 , pile2 = 0;

        for(ll i=1 ; i<n/2 ; ++i)
        {
           pile1 += 1 << i;       
        }  pile1 += 1 << n;  

        for(ll i = n/2 ; i<n ; ++i)
        {
            pile2 += 1 << i;
        }

        cout << pile1 - pile2 << endl;
    }

    return 0;
} 