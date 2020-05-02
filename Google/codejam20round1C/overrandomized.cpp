#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e4;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

void solve()
{
    ll u;
    cin >> u;
    
    string ans(10,'x');
    
        set<char> s;
        map<char,ll> freq;
        for(ll i=0 ; i<maxn ; ++i)
        {
            ll q;
            string m;
            cin >> q >> m;
             
            s.insert(m[m.size()-1]); 
            freq[m[0]]++;
        }
        
        for(ll i=1 ; i<10 ; ++i)
        {
            ll max = minf;
            for(auto x : freq)
            {
                if( x.second > max)
                {
                    ans[i] = x.first;
                    max = x.second;
                }
            }
            freq[ans[i]]=0;
        }

        for(auto x : s)
        {
            if( freq.find(x) == freq.end())
            {
                ans[0] = x;
                break;
            }  
        }  

        cout << ans << endl;
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
        cout << "Case #" << z << ": " ;
        solve();
    }

    return 0;
} 