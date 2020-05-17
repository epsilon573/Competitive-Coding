#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

struct mycomp
{

bool operator () ( const tuple<ll,ll,ll>& t1 , const tuple<ll,ll,ll>& t2)
const
{
    if( (get<0>(t1)) == (get<0>(t2)))
        return (get<1>(t1)) < (get<1>(t2));
    else
        return (get<0>(t1)) > (get<0>(t2));
}

};

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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;

        set<tuple<ll,ll,ll>,mycomp> s;
        vector<ll> ans(n);
        s.insert(make_tuple(n,0LL,n-1));

        for(ll i=1 ; i<=n ; ++i)
        {
            tuple<ll,ll,ll> tmp = *s.begin();
            ll size = get<0>(tmp);
            ll l = get<1>(tmp);
            ll r = get<2>(tmp);
            
            //deb(size); deb(l); deb(r);
            s.erase(s.begin());

            if(size%2) {
                ll idx = (l+r)/2;
                ans[idx] = i;

                if(idx+1 <= r )
                    s.insert( make_tuple( r-idx , idx+1 , r ));
                if(idx-1 >= l )
                    s.insert( make_tuple( idx-l , l , idx-1 ));                
            }
            else {
                ll idx = (l+r-1)/2;
                ans[idx] = i;

                if(idx+1 <= r )
                    s.insert( make_tuple( r-idx , idx+1 , r ));
                if(idx-1 >= l )
                    s.insert( make_tuple( idx-l , l , idx-1 ));                
            }

        }

            for(auto x : ans) cout << x << " " ;
                cout << endl;        
 
    }

    return 0;
} 