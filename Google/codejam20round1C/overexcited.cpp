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

void solve()
{
    string m;
    ll x,y;

    cin >> x >> y >> m;

    pair<ll,ll> target = mp(x,y);

    for(ll i=0 ; i<m.size() ; ++i)
    {
        if(m[i]=='W') { 
            target.first--;
        }
        else if(m[i]=='E') { 
            target.first++;
        }
        else if(m[i]=='N') { 
            target.second++;
        } 
        else if(m[i]=='S') { 
            target.second--;          
        } 

        if( abs(target.first) + abs(target.second) <= i+1 ){
            cout << i+1 << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return; 
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

    for(ll z=1 ; z<=t ; ++z)
    {
        cout << "Case #" << z << ": ";
        solve();        
    }

    return 0;
} 