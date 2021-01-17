// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = 1e15 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n1,n2,n3,s1=0,s2=0,s3=0;
    cin >> n1 >> n2 >> n3;
    vector<ll> v1(n1),v2(n2),v3(n3);

    for(ll i=0 ; i<n1 ; ++i) cin >> v1[i];
    for(ll i=0 ; i<n2 ; ++i) cin >> v2[i];
    for(ll i=0 ; i<n3 ; ++i) cin >> v3[i];

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());

    s1 = accumulate(v1.begin(),v1.end(),0ll);
    s2 = accumulate(v2.begin(),v2.end(),0ll);
    s3 = accumulate(v3.begin(),v3.end(),0ll);
    
    cout << max({s2+s3-s1,s1+s2-s3,s1+s3-s2,s1+s2+s3-2*(v1[0]+v2[0]),s1+s2+s3-2*(v3[0]+v2[0]),s1+s2+s3-2*(v1[0]+v3[0])});   


    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;

    while(t--)
    {
        if(solve())
        {
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 