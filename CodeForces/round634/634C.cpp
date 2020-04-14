#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

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
        ll n; cin >> n;
        vector<ll> v(n); map<ll,ll> cnt;

        for(ll i=0 ; i<n ; ++i)
        {
            cin >> v[i];
            cnt[v[i]]++;
        }

        ll distinct = 0, same = 0;
        for(auto x : cnt)
        {
           if(x.second != 1)
           same = max(x.second,same);

           distinct++;
        }
        

        if(n==1) cout << 0 << endl;
        else if(distinct == n) cout << 1 << endl;
        else if(same == distinct) cout << same-1 << endl;
        else if(same > distinct) cout << distinct << endl;
        else cout << same << endl;

    }

    return 0;
} 