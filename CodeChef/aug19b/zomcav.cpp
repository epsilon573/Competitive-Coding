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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<ll> caves(n),zombies(n),diff(n);

        for(int i=0 ; i<n ; ++i) cin >> caves[i];
        for(int i=0 ; i<n ; ++i) cin >> zombies[i];
          
        ll cnt = 0;
        for(int i=0 ; i<n ; ++i) 
        {
        	if(i-caves[i]>0)
        		diff[i-caves[i]] += 1;
        	if(i+caves[i]<n-1)
        		diff[i+1+caves[i]] -= 1;
        	if(i-caves[i]<=0) ++cnt;
        }
        diff[0] = caves[0] = cnt;
        for(int i=1 ; i<n ; ++i) caves[i] = diff[i] + caves[i-1] ;

        sort(zombies.begin(),zombies.end());
        sort(caves.begin(),caves.end());	
        
        if(zombies == caves) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
} 