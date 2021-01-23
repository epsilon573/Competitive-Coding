// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e6+1;
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

vector<ll> sieve(maxn,1),spf(maxn,0);

void comp()
{
    spf[1] = 1;
    sieve[0] = sieve[1] = 0;
    for(ll i = 2 ; i<maxn ; ++i)
    {
        if(sieve[i])
        {
            spf[i] = i;
            for(ll j=i*i ; j<maxn ; j+=i)
            {   
                sieve[j] = 0;
                if(!spf[j]) spf[j] = i;
            }   
        }
    }
}


bool solve()
{
    ll d;
    cin >> d;

    ll ans = 1;

    for(ll i=d+1,cnt=0 ; cnt<2 ; ++i)
    {
        if(spf[i]==i)
        {
            ans*=i;
            cnt++;
            i+=d-1;
        }

    }

    cout << ans << endl;
    return true;   
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    comp();

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 