#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

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

    ll n; cin >> n;
    vector<ll> v(n);
    
    ll less = 0 , more = 0;

    for(ll i=0 ; i<n ; ++i)
    {
        cin >> v[i];
        if(v[i]<0) less++;
        if(v[i]>0) more++;
    }

    sort(v.begin(),v.end());
    
    if( less&1 )
    {
        cout << 1 << " " << v[0] << endl;
        cout << n-2 << " ";
        for(ll i=1 ; i<n ; ++i) if(v[i]) cout << v[i] << " "; cout << endl;
        cout << "1 0" << endl;    
    }
    else
    {
        cout << 1 << " " << v[0] << endl; 
        cout << n-3 << " ";
        for(ll i=2 ; i<n; ++i) if(v[i]) cout << v[i] << " "; cout << endl;
        cout << "2 0 " << v[1] << endl;   
    }
    

    return 0;
} 