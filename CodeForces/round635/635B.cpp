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
        ll x,n,m;
        cin >> x >> n >> m;
 
        while(x > 20)
        {
            if(n==0) break;
            x = floor(x/2) + 10;
            n--;
        }
 
        if(m*10 - x >= 0) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
 
    return 0;
} 