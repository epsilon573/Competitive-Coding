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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<ll> v(n),ans;

        for(ll i=0 ; i<n ; ++i) cin >> v[i];
        sort(v.begin(),v.end());

        ll start = 0 , end = n-1;
        
        while(start <= end)
        {
            ans.pb(v[end]);
            end--;
            
            if(end < start) break;

            ans.pb(v[start]);
            start++; 
        } 
        reverse(ans.begin(),ans.end());
        for(auto x : ans) cout << x << " " ;
        cout << endl;   
    }

    return 0;
} 