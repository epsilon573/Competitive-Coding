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

ll n,m,x,y;
vector<string> v;

pair<ll,ll> up = mp(0,1) , down = mp(0,-1) , lft = mp(-1,0) , rgt = mp(1,0);
vector<pair<ll,ll>> dir{ up,down,lft,rgt };

pair<ll,ll> add(pair<ll,ll> p1 , pair<ll,ll> p2)
{
    return mp(p1.first+p2.first , p1.second + p2.second);
}

bool is_nbr(pair<ll,ll> parent, pair<ll,ll> target)
{
    if( add(parent,up) == target ) return true;
    if( add(parent,down) == target ) return true;
    if( add(parent,lft) == target ) return true;
    if( add(parent,rgt) == target ) return true;

    return false;
}


std::ostream& operator<< (std::ostream& stream , pair<ll,ll> p)
{
    stream << p.first << "," << p.second ;
    return stream;
}


bool is_inside(ll r, ll c)
{
    return (r < n) && (c < m) && ( r>=0 ) && ( c>=0 );
}

ll cnt_nbr(pair<ll,ll> target)
{
            ll i= target.first, j = target.second , cnt = 0;

            if( is_inside(i-1,j) && v[i-1][j] == '.') cnt++; 
            if( is_inside(i+1,j) && v[i+1][j] == '.') cnt++;
            if( is_inside(i,j+1) && v[i][j+1] == '.') cnt++; 
            if( is_inside(i,j-1) && v[i][j-1] == '.') cnt++;

            return cnt;   
}

bool dfs( pair<ll,ll> parent, pair<ll,ll> target)
{ 
     
    if(is_nbr(parent,target)) return true;
    v[parent.first][parent.second] = 'X';

    for(ll i=0 ; i<4 ; ++i)
    {
        auto next = add(parent, dir[i]);
        
        if(is_inside(next.first,next.second))
        if( v[next.first][next.second] == '.' )
        {
            if(dfs(next,target))
                return true;
        }
    }

    return false;
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
 
    cin >> n >> m;
    pair<ll,ll> parent,target;

    for(ll i=0 ; i<n ; ++i)
    {
        string s; cin >> s;
        v.pb(s);
    }

    cin >> x >> y;
    x--, y--;
    parent.first = x; parent.second=y;

    cin >> x >> y;
    x--, y--;
    target.first = x; target.second=y;    
    
    if(parent == target && cnt_nbr(parent)>=1 ) cout << "YES" << endl;
    else if( is_nbr(parent,target) )
    {
        if( v[x][y] == 'X' ) 
            cout << "YES" << endl;
        else if( v[x][y] == '.' && cnt_nbr(target)>=1 ) 
            out << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else if( dfs(parent, target) )
    {   
        if( v[x][y] == 'X' )
            cout << "YES" << endl;
        else if(v[x][y] == '.' && cnt_nbr(target)>=2) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } 
    else
        cout << "NO" << endl; 
    
    return 0;
} 