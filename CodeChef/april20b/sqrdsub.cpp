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

    ll t,n;
    cin >> t;

    while(t--)
    {
    	ll cnt = 0;
        cin >> n; vector<ll> v(n),idx;
        for(ll i=0 ; i<n ; ++i) 
        	{ 
        		cin >> v[i];
        		if(v[i]%2==0 && v[i]%4!=0) idx.pb(i);
        	}
        
        ll ans = 0;

        for(auto x : idx)
        {
        	ll cnt1=0,cnt2=0,idx1=x-1, idx2=x+1;

        	while(idx1 >= 0)
        	{
        		if(v[idx1]&1) cnt1++;
        		else break;
        		idx1--;
        	}

        	while(idx2 < n)
        	{
        		if(v[idx2]&1) cnt2++;
        		else break;

        		idx2++;
        	}

        	ans += (cnt2+1)*(cnt1+1);

        }

        cout << n*(n+1)/2 - ans << endl; 
        	
    }

    return 0;
}