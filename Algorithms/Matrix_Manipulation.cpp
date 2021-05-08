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

struct matrix
{
    ll n,m;
    vector<vector<ll>> v;

    matrix(ll _n, ll _m)
    {
        n = _n;
        m = _m;
        this->v.assign(n,vector<ll>(m,0));
    }

    void identity()
    {
        for(ll i=0 ; i<v.size() ; ++i)
            for(ll j=0 ; j<m ; ++j)
            {
                if(i==j)
                    v[i][j] = 1;
                else
                    v[i][j] = 0;
            }
    }

    matrix operator *(matrix &a)
    {
        if(m!=a.n)
        {
            cerr << "These Matrices cannot be multiplied!\n";
            assert(false);
        }

        matrix res(n,a.m);

        for(ll i=0 ; i<n ; ++i)
        {
            for(ll col=0 ; col<a.m ; ++col)
            {
                for(ll j=0 ; j<m ; ++j)
                {
                    res.v[i][col] += v[i][j]*a.v[j][col];
                    res.v[i][col] %= mod;
                }
            }
        }

        return res;
    }

    matrix power(ll x)
    {
        if(n!=m)
        {
            cerr << "Exponentiated Matrix is not a square Matrix!\n";
            assert(false);
        }

        matrix res(n,n);
        matrix base = *this;
        res.identity();

        while(x>0)
        {
            if(x&1) res = res*base;
            
            x >>= 1;
            base = base*base;
        }

        return res;
    }

    void print()
    {
        for(ll i=0 ; i<n ; ++i)
        {
            for(ll j=0 ; j<m ; ++j)
            {
                cout << v[i][j] << " ";
            }

            cout << endl;
        }
    }    
};

bool solve()
{
    ll n;
    cin >> n;

    if(n<2)
    {
        cout << n << endl;
        return true;
    }

    matrix base(2,1), main(2,2);

    base.v[0][0] = 1;
    base.v[1][0] = 0;

    main.v[0] = {1,1};
    main.v[1] = {1,0};

    matrix ans = main.power(n-1)*base;

    cout << ans.v[0][0] << endl; 
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