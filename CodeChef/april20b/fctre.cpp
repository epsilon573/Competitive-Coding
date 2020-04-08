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
vector<ll> v[maxn],weight(maxn),path,spf(1000001),sieve(1000001,1);;
bool found = false;
ll ans = 1;

void addEdge(ll x, ll y) 
{ 
    v[x].pb(y); 
    v[y].pb(x); 
} 
 
void printPath() 
{ 
    set<ll> factors;
    vector<ll> cnt(maxn);
    
    cerr << endl << endl;
    for(auto x : path)
    {
        cerr << "Path contains " << x << endl;
        ll j = weight[x];
        while( j>1 )
        {
            factors.insert(spf[j]);
            cnt[spf[j]]++;
            j /= spf[j];
        } 
    }
     
    cerr << endl << endl;
     
    for(auto x : factors)
    {
       // cerr << x << " with power " << cnt[x] << endl;
        ans = (ans*(cnt[x]+1))%mod;
    }
} 

void DFS(ll x,  ll y) 
{ 
    path.push_back(x);
    // cerr << "Pushed " << x << " to path" << endl; 
    if (x == y) 
    { 
    //    cerr << endl << "Path Found" << endl;
        printPath(); 
        return; 
    } 
    vis[x] = true; 

    // int flag = 0; 
    if (!v[x].empty()) { 
        for (int j = 0; j < v[x].size(); j++) { 
            if (vis[v[x][j]] == false) { 
                DFS(v[x][j], y); 
                //flag = 1; 
            } 
        } 
    } 
    
    // if(flag == 0) 
    {
    //    cerr << "Popped " << *(path.end()-1) << " to path" << endl; 
        path.pop_back();
    } 
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

    spf[1] = 1;
    sieve[0] = sieve[1] = 0;
    
    for(ll i = 2 ; i<1000001 ; ++i)
        {
            if(sieve[i])
            {
                spf[i] = i;
                for(ll j=i*i ; j<1000001 ; j+=i)
                {   
                    sieve[j] = 0;
                    if(!spf[j]) spf[j] = i;
                }   
            }
        }

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

        for(ll i=1 ; i<=n ; ++i) cin >> weight[i];

        cin >> q;

        while(q--)
        {
           ans = 1;
           vis = {false};

           ll a,b;
           cin >> a >> b;
           
           for(ll i=0 ; i<maxn ; ++i) vis[i] = false;
           path.clear();
           DFS(a,b);

           cout << ans << endl;
        }
    }

    return 0;
} 