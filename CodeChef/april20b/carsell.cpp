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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,sum=0;
        cin >> n;
        vector<ll> v(n);
        for(ll i=0 ; i<n ; ++i) cin >> v[i];

        sort(v.begin(),v.end(),greater<ll> ());
        
        for(ll i=0 ; i<n ; ++i)
        {
        	if(v[i]-i <= 0) v[i]=0;
        	else v[i] -= i;

            sum = (sum + v[i])%mod;
        }
        
        cout << sum << endl;
    }

    return 0;
} 