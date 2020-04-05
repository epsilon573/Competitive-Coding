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

    ll t;
    cin >> t;

    while(t--)
    {
        ll m,n,price;
        cin >> n >> m;
        vector<ll> v(m+1,INT_MAX),b(n);

        for(int i=0 ; i<n ; i++) { cin >> b[i]; v[b[i]]=0; };
        for(int i=0 ; i<n ; i++) { cin >> price; v[b[i]]+=price;}
        
        //for(int i=1 ; i<=m ; i++) cout << v[i] << " "; 
        price = *min_element(v.begin(),v.end());
        cout << price << endl;
    }

    return 0;
} 