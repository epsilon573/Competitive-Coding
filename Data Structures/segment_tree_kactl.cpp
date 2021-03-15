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

// zero-indexed Segment Tree
struct segTree {

    // default value for empty tree nodes
    static constexpr ll unit = minf;

    // (any associative function)
    ll merge(ll a, ll b) { return max(a,b); }
    
    vector<ll> t; ll n;
    segTree(ll n = 0, ll def = unit) : t(2*n, def), n(n) {}
    
    void update(ll pos, ll val) {
        for (t[pos += n] = val; pos /= 2;)
            t[pos] = merge(t[pos * 2], t[pos * 2 + 1]);
    }

    // queries [b,e)
    ll query(ll b, ll e) {
        ll ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = merge(ra, t[b++]);
            if (e % 2) rb = merge(t[--e], rb);
        }
        return merge(ra, rb);
    }
};

bool solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    segTree tree(n,0);

    for(ll i=0 ; i<n ; ++i)
    {
        tree.update(i,v[i]);
    }
    
    cout << tree.query(0,5);
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