#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

#define mp make_pair
#define pb push_back

#define x first
#define y second

struct seg
{
    pair<ll,ll> p,q;
    seg(const pair<ll,ll>& pr1 , const pair<ll,ll>& pr2)
    {
    	p = pr1;
    	q = pr2;
    }
};

struct mycompare
{
    bool operator() (const seg& s1,const seg& s2)
    {
        return min(s1.p.x,s1.q.x) < min(s2.p.x,s2.q.x);
    }
};


bool intersect1d(ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + eps;
}

int vec(const pair<ll,ll>& a, const pair<ll,ll>& b, const pair<ll,ll>& c) {
    double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < eps ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a,const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
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

    ll n,px,py,qx,qy;
    cin >> n;
    set<seg , mycompare> lines;

    for (int i = 0; i < n; ++i)
    {
    	cin >> px >> py >> qx >> qy;
    	if(px<qx)
        lines.insert( seg(mp(px,py),mp(qx,qy)) );
        else
        lines.insert( seg(mp(qx,qy),mp(px,py)) ); 
    }
    // for(auto it = lines.begin() ; it!=lines.end() ; ++it) cout << (it->p).x << " " << (it->p).y << " "  << (it->q).x << " " << (it->q).y << endl; 
     cout << intersect( *(lines.begin()) , *(++lines.begin()) ) ;
    return 0;
} 
