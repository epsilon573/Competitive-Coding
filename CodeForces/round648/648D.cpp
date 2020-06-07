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

ll n,m,gcnt,bcnt,check;
vector<string> v;

vector<pair<ll,ll>> dir{ mp(1,0),mp(-1,0),mp(0,1),mp(0,-1) };

bool is_inside(ll r, ll c)
{
    return (r < n) && (c < m) && ( r>=0 ) && ( c>=0 );
}

void dfs( ll i, ll j)
{ 
    if( v[i][j] == 'G') check++;
    v[i][j] = '#';

    for(ll k=0 ; k<4 ; ++k)
    {
        ll s = dir[k].first, t = dir[k].second;
        
        if(is_inside(i+s,j+t))
        if( v[i+s][j+t] != '#' )
        {    
            dfs(i+s,j+t);
        }
    }

    return ;
}

bool solve()
{
        gcnt = 0, bcnt = 0;
        cin >> n >> m;
        
        v.clear(); v.resize(n);

        for(ll i=0 ; i<n ; ++i) cin >> v[i];

        for(ll i=0 ; i<n ; ++i)
        for(ll j=0 ; j<m ; ++j)
        {
            if(v[i][j]=='G') gcnt++;
            if(v[i][j]=='B')
            {
                bcnt++;
                for(ll k=0 ; k<4 ; ++k)
                {
                    ll s = dir[k].first, t = dir[k].second;

                    if( is_inside(i+s,j+t) && v[i+s][j+t] == 'G' ){ 
                        return false;
                    }
                    else if( is_inside(i+s,j+t) && v[i+s][j+t] != 'B') v[i+s][j+t] = '#';
                }
            }
        } 

        check = 0;
        
        if( gcnt == 0 ) return true;
        if( v[n-1][m-1] == '#' ) return false;

        dfs( n-1,m-1 );

        if(check==gcnt) return true;
        else return false;   

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

    ll t;
    cin >> t;

    while(t--)
    {
         if(solve()) cout << "Yes" << endl;
         else cout << "No" << endl; 
    }

    return 0;
} 