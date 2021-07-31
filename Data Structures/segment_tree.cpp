// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 2e6+5;
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

ll t[4*maxn],arr[maxn],lazy[4*maxn];

ll merge(ll a, ll b)
{
    return min(a,b);
}

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = merge(t[v*2],t[v*2+1]);
    }
}

void push(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return inf;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

bool solve()
{
    ll n,m,ans=inf;
    cin >> n >> m;
    vector<ll> l(n),r(n);
    vector<pair<ll,ll>> val;

    build(arr,1,0,2*m);

    for(ll i=0,x ; i<n ; ++i)
    {
        cin >> l[i] >> r[i] >> x;
        l[i] *= 2;
        r[i] *= 2;
        val.pb({x,i});
    }

    sort(val.begin(),val.end());
    
    ll x=0, y=0;
    update(1,0,2*m,l[val[0].second],r[val[0].second],1);

    while(y<n && x<=y)
    {
        ll q = query(1,0,2*m,2,2*m);

        if(q!=0)
        {
            ans = min(ans,val[y].first-val[x].first);
            update(1,0,2*m,l[val[x].second],r[val[x].second],-1);
            x++;
        }
        else
        {
            y++;
            if(y<n)
                update(1,0,2*m,l[val[y].second],r[val[y].second],1);
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