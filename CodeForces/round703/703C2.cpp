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

ll n;

ll query(ll l, ll r)
{
    l = max(1ll,l);
    r = min(n,r);

    cout << "? " << l << " " << r << endl;
    cout.flush();

    ll res;
    cin >> res;

    return res;
}

bool solve()
{
    cin >> n;
    
    ll x = query(1,n),ans=-1;

    ll low = 1, high = n-1, mid, left , right;
        
    while(low<high)
    {
        mid = (low+high)/2;
        ll q = query(x-mid, x+mid);

        if(q==x)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }

    if(x-low<1)
        left=-1;
    else
        left = query(x-low,x);
    if(x+low>n)
        right=-1;
    else
        right = query(x,x+low);

    if(left==x)
    {
        cout << "! " << x-low << endl; 
    }
    else
    {
        cout << "! " << x+low << endl;
    }    

    cout.flush();
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