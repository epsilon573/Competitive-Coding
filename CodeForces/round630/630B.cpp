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
    
    vector<ll> sieve(1001,1),spf(1001,0);
    spf[1] = 1, sieve[1] = sieve[0] = 0;
    
    for( ll i=2 ; i<1001 ; ++i)
    {
    	if(sieve[i])
    	{
    		spf[i] = i;
    		for( ll j=i*i ; j<1001 ; j += i)
    		{
    			sieve[j] = 0;
                if(!spf[j]) spf[j] = i;
    		}
    	}
    }
 
    while(t--)
    {
        cin >> n;
        vector<ll> v(n);
        set<ll> s;
        for(ll i=0 ; i<n ; ++i) 
        	{ 
        		cin >> v[i];
                s.insert(spf[v[i]]);
            }
            cout << s.size() << endl;
        for(ll i=0 ; i<n ; ++i) 
        	{ 
                cout << distance(s.begin(),find(s.begin(),s.end(),spf[v[i]])) + 1 << " ";
            }
        cout << endl;    
         
    }

    return 0;
} 