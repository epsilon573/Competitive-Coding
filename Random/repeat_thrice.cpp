#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

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
    ll tmp,tmp2;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<int> sum(30);

        for(int i=0 ; i<n ; i++)
        {
            cin >> tmp;
            tmp2 = tmp;
            for(int j=0 ; tmp2>0 ; ++j)
            {
            	sum[j] = (sum[j] + (1&tmp2))%3;
            	tmp2 = tmp >> (j+1);
            }
            for(int k=0 ; k<4 ; k++) cerr << sum[k] << " ";
            	cerr << endl;
        }
        
        ll ans = 0;
        for(int j=0 ; j<30 ; j++)
            {
            	ans = (ans | (sum[j] << j) ); 
            }
        cout << ans << endl;
    }

    return 0;
} 