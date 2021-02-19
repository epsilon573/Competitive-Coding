// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n,a=0,b=0,c=0,ans=0;
    cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i){
     cin >> v[i];
     if(v[i]%3==0) a++;
     else if(v[i]%3==1) b++;
     else c++;
    }

    ll x = n/3;


for(ll i=0 ; i<10 ; ++i)
{
    if(a<x)
    {
        ans += x-a;
        c -= x-a;
        a = x;

    }
    if(b<x)
    {
        ans += x-b;
        a -= x-b;
        b = x;

    }
    if(c<x)
    {
        ans += x-c;
        b -= x-c;
        c = x;

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