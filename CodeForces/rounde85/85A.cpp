#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;

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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n; string str = "YES";
        ll p,c,pmax = 0,cmax = 0;
        
        for(ll i=0 ; i<n ; ++i)
        {
            cin >> p >> c;
            if(c > p) str = "NO";
            if(p < pmax) str="NO";
            if(c < cmax) str = "NO";
            if(p-pmax< c -cmax ) str = "NO";

            pmax = p , cmax = c;
        }
    cout << str << endl;

    }

    return 0;
} 