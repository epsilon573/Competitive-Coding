#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

#define mp make_pair
#define pb push_back

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
    	ll flag = -1;
        cin >> n;
        string s; cin >> s;

        pair<ll,ll> p = mp(0,0);

        for(ll i=0 ; i<n ; ++i)
        {
            if(flag != 1 && ( s[i] == 'U' || s[i] == 'D' ) )
            {
            	if(s[i] == 'U') p.second += 1;
            	else p.second -= 1;
            	flag = 1;
            }

            if(flag != 0 && ( s[i] == 'L' || s[i] == 'R' ) )
            {
            	if(s[i] == 'L') p.first -= 1;
            	else p.first += 1;
            	flag = 0;
            }
        }

        cout << p.first << " " << p.second << endl;

    }

    return 0;
} 