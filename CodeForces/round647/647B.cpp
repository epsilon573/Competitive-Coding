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

bool solve(ll n)
{
    vector<ll> v(n);
    set<ll> ans;

        for(ll i=0 ; i<n ; ++i){
            cin >> v[i];
            ans.insert(v[i]);
        }
        
        for(ll i=1 ; i<=2049 ; ++i)
        {
            set<ll> tmp;
            for(ll j=0 ; j<n ; ++j)
            {
                tmp.insert(i^v[j]);
            }
            
            if(tmp.size()!=n) continue;
            
            bool flag = true;
            for(auto x=ans.begin(),y=tmp.begin() ; y!=tmp.end() ; ++x,++y)
            {
                if(*x!=*y) {
                    flag = false; break;
                }
            }

            if(flag)
            {
                cout << i << endl;
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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
         
        if(!solve(n)) 
        cout << -1 << endl;     


    }

    return 0;
} 