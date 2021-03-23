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

#ifdef EPSILON

    #define deb(args...)       cerr << "[ " #args << " ] : " , debug(args);
    #define debug(args...)     (Debugger()) , args
 
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
 
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}
 
        private:
        bool first;
        std::string separator;
    };
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
#else
    #define deb(args...)
    #define debug(args...)
#endif

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

// x = a mod m
// x = b mod n 
// m,n need not be coprime works in O(logn)
// returns 0 <= x < lcm(m,n)
// -1 if no solution exists 
ll crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);

    // No Solution
    if((a - b) % g != 0) 
        return -1;

    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

bool solve()
{
    ll n,m,k,gcd,lcm,ans=-1;
    cin >> n >> m >> k;
    vector<ll> a(n),b(m);
    map<ll,ll> posa, posb, sol;

    for(ll i=0 ; i<n ; ++i) cin >> a[i];
    for(ll i=0 ; i<m ; ++i) cin >> b[i];

    if(n>m)
    {
        swap(n,m);
        swap(a,b);
    }

    for(ll i=0 ; i<n ; ++i) posa[a[i]] = i;
    for(ll i=0 ; i<m ; ++i) posb[b[i]] = i;

    gcd = __gcd(n,m);
    lcm = n*m/gcd;


    for(ll i=0 ; i<n ; ++i)
    {
        ll num = a[i];
        deb(num);

        if(!posb.count(num)) continue;

        ll pb = posb[num];
        ll x = crt(i,n,pb,m);

        if(x!=-1)
            sol[num] = x;
    }

    deb(sol);

    ll low = 1 , high = 1e18 , mid;

    while(low<=high)
    {
        mid = (low+high)/2ll;
        ll cnt=0,idx=mid-1;

        for(ll i=0 ; i<n; ++i)
        {
            if(!sol.count(a[i])) continue;
            
            if(idx>=sol[a[i]])
                cnt += 1ll + (idx-sol[a[i]])/(lcm);
        }

        cnt = mid-cnt;

        if(cnt>k)
        {
            high = mid-1;
        }
        else if(cnt<k)
        {
            low = mid+1;
        }
        else
        {
            ans = mid;
            high = mid-1;
        }

        // deb(low,high,cnt);
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