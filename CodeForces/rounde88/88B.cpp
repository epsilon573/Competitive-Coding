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
        ll n,m,c1,c2;
        cin >> n >> m >> c1 >> c2;

        char v[n][m];
        
        for(ll i=0 ; i<n ; ++i) 
        {
            for(ll j=0 ; j<m ; ++j)
            {
                cin >> v[i][j];
            }
        }

        ll cnt1 = 0 , cnt2 = 0;

        for(ll i=0 ; i<n ; ++i) 
        {
            for(ll j=0 ; j<m ; ++j)
            {
                ll cnt = 0 ;

                while( j<m && v[i][j] == '.')
                {
                   // deb("here"); deb(i); deb(j);
                    cnt++;
                    j++;
                }

                cnt1 += (cnt%2);
                cnt2 += (cnt/2);
            }
        }
       // deb(cnt1); deb(cnt2);

        if(2*c1<=c2) 
        {
            cout << (2*cnt2+cnt1)*c1 << endl;
        }
        else
            cout << (cnt2*c2 + cnt1*c1) << endl;
    }

    return 0;
} 