#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

#define deb(x) cout << #x << " " << x << endl

vector<ll> factors[10001];
ll spf[10001],v[10001];

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
     
    // Precalculating primes using Sieve (nlog(logn)) 
    // to calculate Shortest Prime Factor upto n once.
    // Log(n) to calculate prime factorisation for each query

    vector<ll> sieve(10001,1);
    ll t,req_fac; spf[1] = 1;
    sieve[0] = sieve[1] = 0;
    
    cin >> t;
    while(t--)
    {
	    for(ll i = 2 ; i<10001 ; ++i)
	    {
	    	if(sieve[i])
	        {
	            spf[i] = i;
	        	for(ll j=i*i ; j<10001 ; j+=i)
	        	{	
	                sieve[j] = 0;
	                if(!spf[j]) spf[j] = i;
	            }	
	        }
	    }
         
        cin >> req_fac;

        ll j = req_fac;
        while( j>1 )
        {
            factors[req_fac].pb( spf[j] );
            while( spf[j/spf[j]] == spf[j] && j>1 ) j/=spf[j];
            j/=spf[j];
        } 
        
        for(auto x : factors[req_fac] ) cout << x << " "; cout << endl;
    }
    return 0;
} 