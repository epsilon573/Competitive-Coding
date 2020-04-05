#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

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

    ll t,n,b;
    cin >> t;

    for(ll z=1 ; z<=t ; ++z)
    {
    	cout << "Case #" << z << ": ";
    	ll cnt = 0;
        cin >> n >> b;
        vector<ll> v(n);

        for(ll i=0 ; i<n ; ++i) cin >> v[i];
        sort(v.begin(),v.end());

        for(ll i=0 ; i<n ; ++i)
        {
        	b -= v[i];
        	if(b<0) break;
        	else ++cnt;
        }	

        cout << cnt << endl;
    }

    return 0;
} 