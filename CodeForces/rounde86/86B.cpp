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
    string s;
    cin >> t;

    while(t--)
    {
        cin >> s;
        
        if( count(s.begin(),s.end(),'1') == 0 || count(s.begin(),s.end(),'1') == s.size() )
            cout << s << endl;
        else
        {
            for(ll i=0 ; i<s.size() ; ++i) cout << "10" ;
            cout << endl;
        }
    }

    return 0;
} 