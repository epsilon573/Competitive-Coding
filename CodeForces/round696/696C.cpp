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
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb emplace_back
#define endl "\n"

bool solve()
{
    ll n;
    cin >> n;
    n*=2; 
    vector<ll> v(n);
    vector<pair<ll,ll>> ans;
    map<ll,ll> here;

    for(ll i=0 ; i<n ; ++i){
        cin >> v[i];
        here[v[i]]++;
    }
    sort(v.begin(),v.end());

    for(ll i=0 ; i<n-1 ; ++i)
    {
        ans.clear();
        map<ll,ll> m = here;
        ll cnt = 2;

        ll sum = v[n-1];
        m[v[i]]--; m[v[n-1]]--;
        ans.pb(v[i],v[n-1]);

        ll high=n-1;

        while(cnt<n)
        {
            while(m[v[high]]==0) high--;

            m[v[high]]--;

            if(m[sum-v[high]]>0)
            {
                ans.pb(v[high],sum-v[high]);
                m[sum-v[high]]--;
                sum = v[high];

                cnt+=2;
            }
            else
            {
                break;
            }
        }
        
        if(cnt==n)
        {
            cout << "YES" << endl;
            cout << v[i] + v[n-1] << endl;
            for(auto x : ans)
                cout << x.first << " " << x.second << endl;
            return true; 
        }
    }

    cout << "NO" << endl;
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 