#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;

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

    ll t;
    cin >> t;

    while(t--)
    {
    	ll n;
        cin >> n; string str = "YES";

        vector<ll> a(n),b(n);

        for(ll i=0 ; i<n ; ++i) cin >> a[i];
        for(ll i=0 ; i<n ; ++i) cin >> b[i];
        
        set<int> s;

        for(ll i=0 ; i<n ; ++i)
        {
        	if( (a[i] > b[i]) && find(s.begin(),s.end(),-1)==s.end())
        		{  str = "NO"; break; }
        	if( (a[i] < b[i]) && find(s.begin(),s.end(),1)==s.end())
        		{  str = "NO"; break; }

        	s.insert(a[i]);	 
       
        }

        cout << str << endl;	

    }

    return 0;
} 