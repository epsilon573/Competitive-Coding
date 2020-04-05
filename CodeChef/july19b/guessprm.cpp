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

/*    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif */

    ll t;
    cin >> t;

    const ll bait = 1e5;
    
    while(t--)
    {
    	ll bait_rem,num,num_rem;

        cout << 1 << " " << bait << endl;
        cout.flush();
        cin >> bait_rem;
        if(bait_rem == -1) return 0;

        ll fac = bait*bait-bait_rem;
        vector<ll> factors;

        for(ll i=2 ; i<=sqrt(fac) ; ++i)
        {
        	if(fac%i==0)
        	{ 
        		factors.pb(i);
        		while(fac%i==0) fac /= i;
        	}
        }
        if(fac > 1)
        factors.pb(fac);

        for(ll i = sqrt(factors[factors.size()-1]) ;  ; ++i)
        {
            set<ll> remainders;
            for(ll j=0 ; j<factors.size() ; ++j)
            {
            	remainders.insert( (i*i)%factors[j] );
            }
            if( remainders.size() == factors.size() ) 
            {
            	num = i*i;
            	break;
            }

        }

        cout << 1 << " " << sqrt(num) << endl;
        cout.flush();
        cin >> num_rem;
        if(num_rem == -1) return 0;

        for(ll j=0 ; j<factors.size() ; ++j)
        {
           	if( num%factors[j] == num_rem )
           	{	
            	cout << 2 << " " << factors[j] << endl;
            	cout.flush();
            	break;
           	} 
        }
        
        string s;
        cin >> s;
        if(s=="Yes") continue;
        else return 0;

    }

    return 0;
} 