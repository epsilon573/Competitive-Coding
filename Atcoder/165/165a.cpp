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

    ll k,a,b;
    cin >> k >> a >> b;

    ll rem1,rem2;

    rem1 = a%k , rem2 = b%k;
    if(rem1==0 || rem2==0) 
    {
        cout << "OK" << endl; return 0;
    }

    else if( (a+k-rem1)/k < (b+k-rem2)/k) 
          {
        cout << "OK" << endl; return 0;
    }

    cout << "NG" << endl;

    return 0;
} 