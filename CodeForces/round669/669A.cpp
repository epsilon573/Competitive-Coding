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

bool solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    ll numo = count(v.begin(),v.end(),1);
    ll numz = count(v.begin(),v.end(),0);
    

    if(numz >= n/2){ 
                     cout << n/2 << endl;
                     for(ll i=0 ; i<n/2 ; ++i) cout << 0 << " "; 
                 }
    else{
           if((n/2)&1) { 
                           cout << n/2 + 1 << endl;
                           for(ll i=0 ; i<n/2+1 ; ++i) cout << 1 << " ";
                        }
        
        else{   
             cout << n/2 << endl;
             for(ll i=0 ; i<n/2 ; ++i) cout << 1 << " "; 
             }  
       }
            cout << endl;
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