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
    ll n;
    cin >> n;

    for(ll i=1 ; i<=1e4 ; ++i)
    {
        ll x = i*i*i;

        ll low = 1 , high = 1e4;

        while(low<=high)
        {
            ll mid = (low+high)/2;

            ll y = mid*mid*mid;

            if(x+y<n)
            {
                low = mid+1;
            } 
            else if(x+y>n)
            {
                high = mid-1;
            }
            else
            {
                return true;
            }
        }
    }
    
    return false;    
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
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
} 