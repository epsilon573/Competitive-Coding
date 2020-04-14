#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

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
        string s[9];
        for(ll i=0 ; i<9 ; ++i) cin >> s[i];
            
        s[0][0]=='9' ? s[0][0] = '1' : s[0][0] += 1;
        s[1][3]=='9' ? s[1][3] = '1' : s[1][3] += 1;
        s[2][6]=='9' ? s[2][6] = '1' : s[2][6] += 1;
        s[3][1]=='9' ? s[3][1] = '1' : s[3][1] += 1;
        s[4][4]=='9' ? s[4][4] = '1' : s[4][4] += 1;
        s[5][7]=='9' ? s[5][7] = '1' : s[5][7] += 1;
        s[6][2]=='9' ? s[6][2] = '1' : s[6][2] += 1;
        s[7][5]=='9' ? s[7][5] = '1' : s[7][5] += 1;
        s[8][8]=='9' ? s[8][8] = '1' : s[8][8] += 1;


      for(ll i=0 ; i<9 ; ++i) cout << s[i] << endl;
    }

    return 0;
} 