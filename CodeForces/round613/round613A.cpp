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

    ll t,a,b;
    cin >> t;

    while(t--)
    {
        ll a,b;
        cin >> a >> b;
        if(b==a) cout << "0" << endl;
        else if( (b>a && (b-a)%2==1) || (b<a && (b-a)%2==0) ) cout << "1" << endl;
        else cout << "2" << endl;
    }

    return 0;
} 