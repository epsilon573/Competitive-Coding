#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

#define mp make_pair
#define pb push_back 

vector<ll> varr[1000001];

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
        for(int i=0 ; i<1000001 ; ++i) varr[i].clear();
        cin >> n; vector<ll> num(n);
        for(int i=0 ; i<n ; ++i) cin >> num[i];
        
        ll xr=0,ans=0; varr[0].pb(-1);

        for(int i=0 ; i<n ; ++i) { xr = xr^num[i]; varr[xr].pb(i); }
        
        for(int i=0 ; i<1000001 ; ++i) 
        {
            // if(varr[i].size()) cerr << i << " " << varr[i].size() << endl;
            for(int j=0 ; j<varr[i].size() ; ++j)
            {
                ans += j*varr[i][j] - (varr[i].size()-1-j)*varr[i][j];  
            }
            ans -= varr[i].size()*(varr[i].size()-1)/2;
        }
        cout << ans << endl; 

    }

    return 0;
} 