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
    
    ll n;
    cin >> n;
    vector<ll> prefix(n+1);
    prefix[0] = 0;

    cerr << "0 ";
    for(ll i=1,tmp ; i<=n ; ++i)
    {
    	cin >> tmp;
    	prefix[i] = prefix[i-1]+tmp;
    	cerr << prefix[i] << " ";
    }

    set<ll> s; 
    ll begin = 0 , end = 0  , ans = 0;
    s.insert(0);

    for(ll i=1 ; i<=n ; ++i)
    {
    	if(!s.count(prefix[i]))
    	{
    	  // cerr << "Inserted " << prefix[i] << endl;
           s.insert(prefix[i]);
           end++;
           continue;
    	}
        
        s.erase(prefix[begin]);
    	ans += end - begin;
    	--i; 
    	begin++;
    }
     
    while(begin < end) 
    	{ 
    		ans += end - begin;
    		begin++;
    	} 

    cout << ans;

    return 0;
} 