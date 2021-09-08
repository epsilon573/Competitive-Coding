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

ll gsign(ll x)
{
    if(x<0)
        return -1;
    else if(x>0)
        return 1;
    else
        return 0;
}

struct node{
    ll pref,suff,best,sz,psign,ssign;

    node(ll x)
    {
        sz = 1;
        psign = ssign = gsign(x);
        pref = suff = best = 1*abs(gsign(x));
    }

}; 

// zero-indexed Segment Tree
struct segTree {

    // default value for empty tree nodes
    node unit = node(0);

    // (any associative function)
    node merge(node a, node b) { 
        node res(0);
        res.sz = a.sz + b.sz;

        ll new_best = 0;
        if(b.psign<=a.ssign)
            new_best = a.suff + b.pref;

        res.best = max({new_best,a.best,b.best});
        res.psign = a.psign;
        res.ssign = b.ssign;

        if(a.suff==a.sz && a.ssign!=0)
        {
            if(b.psign<=a.ssign)
            {
                res.pref = a.sz + b.pref;
            }
            else
            {
                res.pref = a.pref;         
            }
        }
        else{
            res.pref = a.pref;
        }

        if(b.pref==b.sz && b.psign!=0)
        {
            if(b.psign<=a.ssign)
            {
                res.suff = b.sz + a.suff;
            }
            else
            {
                res.suff = b.suff;
            }
        }
        else{
            res.suff = b.suff;
        }

        return res;
    }
    
    vector<node> t; ll n;
    segTree(ll n = 0, node def = node(0)) : t(2*n, def), n(n) {}
    
    void update(ll pos, node val) {
        for (t[pos += n] = val; pos /= 2;)
            t[pos] = merge(t[pos * 2], t[pos * 2 + 1]);
    }

    // queries [b,e)
    node query(ll b, ll e) {
        node ra = node(0), rb = node(0);
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = merge(ra, t[b++]);
            if (e % 2) rb = merge(t[--e], rb);
        }
        return merge(ra, rb);
    }
};

bool solve()
{
    ll n,q;
    cin >> n;
    vector<ll> v(n),diff(n,0);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    segTree t(n,0);
    diff[0] = v[0];

    for(ll i=1 ; i<n ; ++i)
        diff[i] = v[i] - v[i-1];

    for(ll i=1 ; i<n ; ++i)
        t.update(i,node(diff[i]));

    cin >> q;
    while(q--)
    {
        ll l,r,d;
        cin >> l >> r >> d; 
        l--;

        diff[l] += d;
        if(r!=n) diff[r] -= d;

        if(l!=0)
            t.update(l,node(diff[l]));

        if(r!=n)
            t.update(r,node(diff[r]));

        cout << 1+t.query(0,n).best << endl;
    }

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
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 