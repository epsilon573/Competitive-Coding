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
    ll t,n,m; spf[1] = 1;
    sieve[0] = sieve[1] = 0;
    
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
     
    for(ll req_fac=2 ; req_fac<200 ; ++req_fac)
    {
        ll j = req_fac;
        while( j>1 )
        {
            factors[req_fac].pb( spf[j] );
            while( spf[j/spf[j]] == spf[j] && j>1 ) j/=spf[j];
            j/=spf[j];
        } 
    }

    
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<ll> b(10001);
        for(ll i=0 ; i<n ; ++i)
        {
            cin >> v[i];
            for( auto x : factors[v[i]] )
            {
                ll cnt = 0;
                while( v[i]%x == 0 && v[i]>1 ) { ++cnt ; v[i] /= x;}
                b[x] = max(cnt,b[x]);  
            }
        }
        
        ll ans = 1, ans_idx = 1, curr , tmp;

        for(ll i=2 ; i<=m ; ++i)
        {
            curr = 1 , tmp = i;
            for( auto x : factors[tmp] )
            {
                ll cnt = 0;
                while( tmp%x == 0 ) { ++cnt ; tmp /= x;}
                if(cnt > b[x]) curr = curr * pow(x,cnt-b[x]);
            }
            if( curr > ans ) { ans = curr; ans_idx = i; }
        }
        
        cout << ans_idx << endl;
    }

    return 0;
} 