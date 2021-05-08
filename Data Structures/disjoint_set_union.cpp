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
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

struct dsu {
    vector<ll> e;
    dsu(ll n) : e(n, -1) {}
    bool sameSet(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return -e[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

bool solve()
{
    ll n,p,comps,cost=0;
    cin >> n >> p;
    vector<ll> v(n),idx(n);

    dsu d(n);
    comps = n;
    iota(idx.begin(),idx.end(),0);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    sort(idx.begin(),idx.end(),[&](ll a, ll b)
    {
        return v[a] < v[b];
    });
    
    for(ll i=0 ; i<n ; ++i)
    {
        ll here = idx[i];
        if(v[here]>=p) break;

        if(d.size(here)>1) continue;

        for(ll j=here-1 ; j>=0 ; --j)
        {
            if(__gcd(v[j],v[here])!=v[here]) break;

            if(d.size(j)>1)
            {
                d.join(j,here);
                comps--;
                cost += v[here];
                break;
            }
            else
            {
                d.join(j,here);
                comps--;
                cost += v[here];
            }
        }

        for(ll j=here+1 ; j<n ; ++j)
        {
            if(__gcd(v[j],v[here])!=v[here]) break;
            
            if(d.size(j)>1)
            {
                d.join(j,here);
                comps--;
                cost += v[here];
                break;
            }
            else
            {
                d.join(j,here);
                comps--;
                cost += v[here];
            }
        }
    }

    cout << cost + (comps-1)*p << endl;
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
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 