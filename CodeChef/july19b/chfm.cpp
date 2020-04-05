#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

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
       db mean = 0 ;
       cin >> n; vector<ll> v(n);
       for(ll i=0 ; i<n ; ++i) cin >> v[i], mean += v[i];

       mean /= n;
       if( find(v.begin(),v.end(),mean) != v.end() )
       cout << distance(v.begin(),find(v.begin(),v.end(),mean)) + 1 << endl;
       else 
       cout << "Impossible" << endl;
    }

    return 0;
} 