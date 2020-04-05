#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

#define deb(x) cout << #x << " " << x << endl

ll string_mod(string num, ll a) 
{ 
    ll res = 0; 
  
    for (ll i = 0; i < num.length(); i++) 
         res = (res*10 + num[i] - '0') %a; 
  
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

    ll t,n;
    string k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        ll ones = string_mod(k,n);
        ll zeroes = n - ones;

        if(ones == zeroes) cout << 2*ones - 1 << endl;
        else cout << min(ones,zeroes)*2 << endl; 

    }

    return 0;
} 