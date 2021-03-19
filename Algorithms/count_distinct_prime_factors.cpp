// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
typedef int ll;
typedef long double ld;

const ll maxn = 2e5+5;

#define mp make_pair
#define pb push_back
#define endl "\n"

ll spf[maxn],fac[maxn];

void sieve()
{
    spf[1] = 1;
    for(ll i = 2 ; i<maxn ; ++i)
    {
        if(!spf[i])
        {
            spf[i] = i;
            for(ull j= (ull)i*(ull)i ; j<maxn ; j+=i)
            {   
                if(!spf[j]) spf[j] = i;
            }   
        }
    }
}

void factor()
{
    for(ll i=1 ; i<maxn; ++i)
    {
        ll tmp = i,ans=0,prev;

        while(spf[tmp]!=1)
        {
            prev = spf[tmp];
            tmp /= spf[tmp];

            if(spf[tmp] == prev) ans += fac[tmp];
            else ans += fac[tmp]+1;

            break;  
        }

        fac[i] = ans;
    }
}

bool solve()
{
    ll c,d,x,ans=0;
    cin >> c >> d >> x;

    for(ll i=1 ; i<=sqrt(x) ; ++i)
    {
        if(x%i==0)
        {
            ll tmp = x/i + d;

            if(tmp%c==0)
            {
                ll here = tmp/c;
                ans += 1<<fac[here];
            } 
        }
        else continue;

        if(x/i != i)
        {
            ll tmp = i + d;

            if(tmp%c==0)
            {
                ll here = tmp/c;
                ans += 1<<fac[here];
            }             
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

    sieve();
    factor();

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 