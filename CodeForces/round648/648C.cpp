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

    ll n;

        cin >> n;
        vector<ll> a(n),b(n),c(n),cnt(n);

        for(ll i=0 ; i<n ; ++i)
        {
            cin >> a[i]; a[i]--;

            c[a[i]] = i;
        }

        for(ll i=0 ; i<n ; ++i)
        {
            cin >> b[i]; b[i]--;
        }

        for(ll i=0 ; i<n ; ++i)
        {
            ll num;
            if(c[b[i]] < i)
            {
                num = c[b[i]]+n-i;
            }
            else num = c[b[i]] - i;

            cnt[num]++;
        }

        cout << *max_element(cnt.begin(),cnt.end()) << endl;
    

    return 0;
} 