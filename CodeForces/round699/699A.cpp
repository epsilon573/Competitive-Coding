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
    ll x,y;
    cin >> x >> y;

    string s; cin >> s;
    ll n = s.size();

    ll curx=0 , cury=0, bestx=0, minx=0 , besty=0, miny=0;

    for(ll i=0 ; i<n ; ++i)
    {
        if(s[i]=='R') bestx++;
        if(s[i]=='L') minx--;
        if(s[i]=='U') besty++;
        if(s[i]=='D') miny--;
    }
    
    return (x<=bestx && x>=minx && y<=besty && y>=miny);
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