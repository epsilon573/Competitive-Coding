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

struct comp
{
    bool operator() ( const char& a , const char& b) const
    {
        return a > b;
    }
};

bool solve()
{
    ll n; string a,b;
    cin >> n >> a >> b;

    set<char, comp > dic;
    map<char,set<int>> m,z;
    vector<set<int>> ans;

    for(ll i=0 ; i<n ; ++i)
    {
        z[a[i]].insert(i);
        m[b[i]].insert(i);
        dic.insert(b[i]);
    }

    for(auto x : dic)
    {
        // cerr << x << " " << z[x].size() << endl;
        if(z[x].size()==0) return false;
        
        bool flag = false;
        set<int> tmp;
        for(auto y : m[x])
        {
            // cerr << "checking " << y << " " << a[y] << "against" << x << endl;
            if(a[y] < x)
                return false;
            
            if( a[y]!=x )
            {
                flag = true;
                z[a[y]].erase(y);
            }

            tmp.insert(y);
        }
        
        if(flag)
        {
            tmp.insert( *z[x].begin() );
        
            for( auto p : tmp ) 
                z[x].insert(p);

            ans.pb(tmp);
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans)
    {
        cout << x.size() << " ";
        for(auto y : x)
            cout << y << " ";
        cout << endl;
    }


    return true;    
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
        if(!solve())
            cout << -1 << endl;
        cerr << endl << endl;
    }

    return 0;
} 