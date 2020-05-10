#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e5+2;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

vector<ll> adj[maxn];

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
    
    ll n,k,depth=0,z;

    cin >> n >> k;

    for(ll i=1,tmp ; i<=n ; ++i)
    {
        cin >> tmp;
        adj[i].pb(tmp);
    }
    
    queue<ll> q;
    map<ll,ll> d2c,c2d;
    q.push(1);
    c2d[1] = depth;
    d2c[0] = 1;
    bool flag = true;
    ll start_depth,end_depth;

    while(flag)
    {
        z = q.front();
        q.pop();

        for(auto x : adj[z])
        {
            if(c2d.find(x)!=c2d.end()) 
            {
                end_depth = depth+1;
                start_depth = c2d[x];
                flag = false; break;
            }
            
            depth++; 
            q.push(x);

            d2c[depth] = x;
            c2d[x] = depth;
        }

    }

    if( k < start_depth)
    cout << d2c[k];
    else
    {
        k -= start_depth;

        k %= (end_depth-start_depth);

        cout << d2c[start_depth + k];
    }

    return 0;
} 
