#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

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

    ll t,x,k;
    cin >> t;

    while(t--)
    {
        cin >> x >> k;
        vector<ll> factors;
        for(ll i=2 ; i<=sqrt(x) ; ++i)
        {
            while(x%i==0)
            {
            	factors.pb(i);
            	x /= i;
            }
        }
        if(x>1) factors.pb(x);

        if(factors.size()>=k) cout << "1" << endl;
        else cout << "0" << endl;
 
    }

    return 0;
} 