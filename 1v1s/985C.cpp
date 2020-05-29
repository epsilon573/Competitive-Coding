// Author : Epsilon573
// If it works, don't touch it.

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

    ll n,k,l; 
    cin >> n >> k >> l;
    
    ll m = n*k;
    vector<ll> v(m);

    for(ll i=0 ; i<m ; ++i) cin >> v[i];

    sort(v.begin(),v.end());
   
    vector<ll> ans;
    ans.pb(v[0]);
    
    ll i=1;
        while( i<m && v[i] - v[0] <= l){
            ans.pb(v[i]);
            ++i;
        }
        

    if(ans.size() < n) 
    {
        cout << 0 << endl;
        return 0;
    }

    if(n==1) 
    {
        cout << ans[0] << endl;
        return 0;
    }
    
    ll res = 0 , cnt = 0;
    vector<ll> barrell;

    for( ;; )
    {

        if( cnt + ans.size() == n )
            break;
        
        if(barrell.size() == k) 
        {
            barrell.clear();
        }

        if(barrell.size() == 0){ 
            cnt++;
            res += ans[0];
        }
 
        barrell.pb(ans[0]);
        ans.erase(ans.begin()); 
    }

    res = accumulate(ans.begin(),ans.end(),res);

    cout << res ;   
         

    return 0;
}