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

    int t;
    cin >> t;

    for(int i=1 ; i<=t ; ++i)
    {
         cout << "Case #"<<i << ": ";

         int n,k,ans=0;
         cin >> n >> k;

         vector<int> v(n);

         for(ll j=0 ; j<n ; ++j) cin >> v[j];

         for(ll j=0 ; j<n ; ++j)
            {
                if(v[j]==k && j<n-1)
                {
                    while(j < n)
                    {
                       if(v[j] - v[j+1] != 1)
                           break;
                        else
                           j++;

                        if(v[j] == 1){
                           ans++;
                           break;
                        }
                    }
                }
            }

         cout << ans << endl;   

    }

    return 0;
} 