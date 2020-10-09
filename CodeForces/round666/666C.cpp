// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e12;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl


bool solve()
{
    ll n; cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    if(n==1)
    {
        cout << "1 1" << endl << "0" << endl;
        cout << "1 1" << endl << -v[0] << endl;
        cout << "1 1" << endl << "0" << endl;
    }
    else if(n==2)
    {
        cout << "2 2" << endl << -v[1] << endl;
        cout << "1 1" << endl << -v[0] << endl;
        cout << "1 2 "<< endl << "0 0" << endl;
    }
    else
    {
            cout << "2 " << n << endl;

            for(ll i=1 ; i<n ; i++){
                cout << v[i]*(n-1) << " ";
                v[i] += v[i]*(n-1);
            }
            
            cout << endl;

            cout << 1 << " " << 1 << endl;
            cout << -v[0] << endl;
            v[0]=0;

            cout << "1 " << n << endl;
            for(ll i=0 ; i<n ; i++){
                cout << -v[i] << " " ;
            }

            cout << endl;
    }

    return true;    
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

    ll t=1;

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