// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

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
        string s; ll k,n;
        cin >> n >> k >> s; 
        
        vector<string> str(k);
        ll total = count(s.begin(),s.end(),'1');
        ll ans = total;

        for(ll i=0 ; i<n ; ++i)
        {
            str[i%k] += s[i];
        }
          
        for(ll i=0 ; i<k ; ++i)
        {
            ll sz = str[i].size();
            vector<ll> dp(sz+1);
            ll ones = 0;
            ll all = count(str[i].begin(),str[i].end(),'1');
            dp[0] = 0;
            ll tmp = all;

            for(ll j=0 ; j<sz ; ++j)
            {
                bool flag = false;
                if( str[i][j] == '1') 
                    flag = true;
                
                if( !flag )
                dp[j+1] = min( ones + 1 , dp[j] + 1);
                if( flag )
                { 
                    dp[j+1] = min( ones , dp[j] );
                    ones++;
                }

                tmp = min( tmp , dp[j+1] + all - ones );
            }

            ans =  min( ans, tmp + total - all);
        }

        cout << ans << endl;
    }

    return 0;
} 