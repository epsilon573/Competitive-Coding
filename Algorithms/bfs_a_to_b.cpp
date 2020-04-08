#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e6+1;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

vector<bool> vis(maxn);
vector<ll> v[maxn],lvl(maxn),parent(maxn);
bool found = false;
queue<ll> qu; 

void addEdge(ll x, ll y) 
{ 
    v[x].pb(y); 
    v[y].pb(x); 
} 
 
void bfs()
{  
   while(!qu.empty())
   { 
        ll z = qu.front();
        qu.pop();

        for(auto x : v[z])
        {
            if(!vis[x])
            {
                qu.push(x);
                vis[x] = 1;
                parent[x] = z;
                lvl[x] = lvl[z] + 1;  
            }
        }
    }
}

void findPath( ll node1 , ll node2)
{
    vector<ll> path1,path2;
    path1.pb(node1) , path2.pb(node2);
    while( node1 != node2)
    {
        if( lvl[node1] > lvl[node2] )
        {
            node1 = parent[node1];
            path1.pb( node1 );
        }
        else if( lvl[node1] < lvl[node2] ) 
        {
            node2 = parent[node2];
            path2.pb( node2 );
        }
        else if( lvl[node1] == lvl[node2] )
        {
            node1 = parent[node1];
            node2 = parent[node2];
            path1.pb( node1 );
            path2.pb( node2 );
        }
    }    
    path2.pop_back();

    for(auto x : path1) cout << x << " -> ";
    for(ll i=path2.size()-1 ; i>0 ; --i) cout << path2[i] << " -> ";
    cout << path2[0];    
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
        ll n,q;
        cin >> n;
          
        for(ll i=0 ; i<maxn ; ++i) v[i].clear();

        for(ll i=0 ; i<n-1 ; ++i)
        {
            ll a,b;
            cin >> a >> b;
            addEdge(a,b);
        }

        qu.push(1);
        vis[1] = 1;
        lvl[1] = 0;
        parent[1] = 0;

        bfs();
  
        findPath(1,8);
        cout << endl;
        findPath(5,8);

    }

    return 0;
} 