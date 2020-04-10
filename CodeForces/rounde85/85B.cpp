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

    ll t,n,x;
    cin >> t;

    while(t--)
    {
    	ll cnt = 0 , sum=0;
        cin >> n >> x; vector<ll> v(n),b;
        for(ll i=0 ; i<n ; ++i) 
        	{ 
        		cin >> v[i];
                if(v[i] - x == 0 ) cnt++;
                else if(v[i] - x > 0 ) cnt ++, sum += v[i] - x;
                else b.pb(x-v[i]); 
        	}

        sort(b.begin(),b.end());	
        for(ll i=0 ; i<b.size() ; ++i)
        {
        	cerr << sum << " " << b[i] << endl; 
            sum -= b[i];
            if(sum < 0) break;
            else cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
} 