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
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

bool solve()
{
    ll x;
    string s;
    cin >> s;
    cin >> x;
    
    ll n= s.size();
    string ans(n,'1');
    
    for(ll i=0 ; i<n ; ++i)
    {
        if( i-x < 0 && i+x >= n )
        {
            if(s[i]=='1') return false;
            else ans[i] = '0';
        }
    }

    for(ll i=0 ; i<n ; ++i)
    {
        if(s[i]=='0')
        {
            if(i+x<n) ans[i+x] = '0';
            if(i-x>=0) ans[i-x] = '0';
        }
    }

    for(ll i=0 ; i<n ; ++i)
    {
        if(s[i]=='1')
        {
            if( i+x<n && i-x>=0 )
            {
                if( ans[i+x]=='0' && ans[i-x]=='0' )
                    return false;
            }
            else if(i+x<n)
            {
                if(ans[i+x]=='0') return false;
                ans[i+x] = '1';
            }
            else if(i-x>=0)
            {
                if(ans[i-x]=='0') return false;
                ans[i-x] = '1';
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

    #ifndef ONLINE_JUDGE
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
            cout << -1 << endl;
        }
    }

    return 0;
} 