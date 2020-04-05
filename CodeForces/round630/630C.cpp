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
    	ll ans = 0,n,k;
    	cin >> n >> k;
    	ll strcnt = n/k;
        string s;
        cin >> s;

if(k>1)
{
        for(ll i=1 ; i<=k/2 ; ++i)
        {
        	vector<ll> cnt(27,0);
        	for(ll j=0, idx = i-1 ; j<strcnt ; ++j,idx+=k)
        	{ 
                 	cnt[ s[ idx ] - 'a']++;
        	}
        	for(ll j=0, idx = k-i ; j<strcnt ; ++j,idx+=k)
        	{ 
                    cnt[ s[idx] - 'a']++; 
        	}
        	sort(cnt.begin(),cnt.end());
        	ans += accumulate(cnt.begin(),cnt.end()-1,0);
        }
 }       


        if(k&1)
         {
            vector<ll> cnt(27,0);
            for(ll j=0, idx = (k-1)/2 ; j<strcnt ; ++j,idx+=k)
        	{ 
                 	cnt[ s[ idx ] - 'a']++;
        	}
            sort(cnt.begin(),cnt.end());
        	ans += accumulate(cnt.begin(),cnt.end()-1,0);
          }	
           
        cout << ans << endl;

    }

    return 0;
} 
