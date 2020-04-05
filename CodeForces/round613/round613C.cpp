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

    ll t,n,m;
    cin >> t;
    while(t--)
    {
    	string s;
        cin >> n >> m;
        cin >> s;
        vector<vector<int>> v;
        vector<int> c(26),tries(m);
        for(int i=0 ; i<m ; i++) cin >> tries[i];
        for(int i=0 ; i<n ; i++)
        {
            ++c[s[i]-'a'];
            v.push_back(c);
        }
        ll ans;
        for(int j=0 ; j<26 ; j++)
        {
        ans=0;
        for(int i=0 ; i<m ; i++)
        {
            ans+=v[tries[i]-1][j];
        }
        ans+=v[n-1][j];
        cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
} 