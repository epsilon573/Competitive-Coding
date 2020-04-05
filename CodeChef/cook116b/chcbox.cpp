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

    ll t,n,mx;
    cin >> t;

    while(t--)
    {
       cin >> n; 
       vector<ll> v(n),idx;
       for(ll i=0 ; i<n ; ++i) cin >> v[i];

       ll ans = 0 , dist ;
 
       mx = *max_element(v.begin(),v.end());
       for(ll i=0 ; i<n ; ++i)
       {
       	   if(v[i]==mx) idx.push_back(i);
       }

       for(ll i=0 ; i<idx.size()-1 ; ++i) 
       {
       	    dist = idx[i+1] - idx[i] - 1;
        	if( dist >= n/2 ) ans += ( dist - n/2 + 1) ;
       }

        dist = idx[0] + (n-1) - idx[idx.size()-1];
  
        if( dist >= n/2  ) ans += ( dist - n/2 + 1); 

        cout << ans << endl; 	 
       
    }

    return 0;
} 