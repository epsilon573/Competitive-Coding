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

    ll n;
    cin >> n;

    switch(n%10)
    {
        case 0: cout << "pon";
        break;
        case 1: cout << "pon";
        break;
        case 2: cout << "hon";
        break;
        case 3: cout << "bon";
        break;
        case 4: cout << "hon";
        break;
        case 5: cout << "hon";
        break;
        case 6: cout << "pon";
        break;
        case 7: cout << "hon";
        break;
        case 8: cout << "pon";
        break;
        case 9: cout << "hon";
        break;

    }

    return 0;
} 