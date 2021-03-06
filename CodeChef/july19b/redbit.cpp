#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 998244353;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

ll bin_power_mod(ll base, ll power, ll m) 
{
    base %= m;
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res = res * base % m;
        base = base * base % m;
        power >>= 1;
    }
    return res;
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
        string s;
        cin >> s;
    }

    return 0;
} 