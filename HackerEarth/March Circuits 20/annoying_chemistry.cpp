#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

#define mp make_pair
#define pb push_back
 
 ll lcm(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 }

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

    ll a,b,c,d,tmp;
    cin >> a >> b >> c >> d;

    tmp = lcm( (lcm(a,c)/c) , (lcm(b,d)/d) );

    cout << tmp*c/a << " " << tmp*d/b << " " << tmp; 

    return 0;
} 