#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,xr = INT_MAX;
        cin >> n;
        vector<ll> v(n);
        for(int i=0 ; i<n ; ++i) cin >> v[i];

        sort(v.begin(),v.end());
        for(int i=0 ; i<n-1 ; ++i) xr = min(xr,v[i]^v[i+1]);

        cout << xr << endl; 
    }

    return 0;
} 