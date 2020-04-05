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

    ll t;
    cin >> t;

    for(ll x=1 ; x<=t ; ++x)
    {
        cout << "Case #"<< x << ": " ;
        ll n,trace=0;
        cin >> n;

        set<ll> rows[n],cols[n];
        for(ll i=0 ; i<n ; ++i)
        {
        	for(ll j=0,tmp ; j<n ; ++j)
        	{
        		cin >> tmp;
        		rows[i].insert(tmp);
        		cols[j].insert(tmp);
        		if(i==j) trace += tmp;
        	}
        }

        ll cntr = 0 , cntc = 0;
        for(ll i=0 ; i<n ; ++i)
        {
        	if(rows[i].size()!=n) cntr++;
        	if(cols[i].size()!=n) cntc++;
        }

        cout << trace << " " << cntr << " " << cntc << endl;
    }

    return 0;
} 