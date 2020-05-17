#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e6+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

ll spf[maxn];

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

    for(ll i=0 ; i<maxn ; ++i) spf[i] = i;
    
        for(ll i = 2 ; i<1000001 ; ++i)
        {
            if(spf[i]==i)
            {
                for(ll j=i*i ; j<1000001 ; j+=i)
                {   
                    if(spf[j] == j) spf[j] = i;
                }   
            }
        }

    while(t--)
    {
        ll n,k;
        cin >> n >> k;

        k--;

        n += spf[n];
        n += 2LL*k;

        cout << n << endl;
    }

    return 0;
} 