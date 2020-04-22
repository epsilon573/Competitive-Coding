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

    ll t,n,k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k ;
        vector<ll> diff(2*k+1, 0) , v(n+1);

        for(ll i=1 ; i<=n ; ++i) cin >> v[i];

        for(ll i=1 ; i<=n/2 ; ++i)
        {
            ll a = v[i];
            ll b =  v[n-i+1]; 
            ll sum = a + b;
            ll min_sum = min(a,b) + 1;
            ll left = 2, right = 2*k ;
            ll max_sum = max(a,b) + k;

            if( sum > min_sum )
            {
                diff[sum] -= 1;
                diff[min_sum] += 1;

                if(min_sum > left)
                {
                    diff[min_sum] -= 2;
                    diff[left] += 2;
                }
            }

            if( sum < max_sum)
            {
                diff[sum+1] += 1;

                if( max_sum < right )
                {
                    diff[max_sum + 1] -= 1;
                    diff[max_sum + 1] += 2;
                }
            }
            diff[0] = diff[1] = LLONG_MAX;
        }   
       
       for(ll i=2 ; i<2*k ; ++i)
       {
           diff[i+1] += diff[i];
       }
       cout << *min_element(diff.begin(), diff.end()) << endl; 
    }

    return 0;
} 