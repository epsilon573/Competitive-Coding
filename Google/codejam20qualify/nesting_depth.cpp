#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

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

    for(ll x=1 ; x<=t ; ++x)
    {
        cout << "Case #"<< x << ": " ;
        string inp,s; 
        cin >> inp;
        s = '0' + inp + '0';

        for(ll i=0 ; i<s.size()-1 ; ++i)
        {
            ll tmp = s[i+1] - s[i];
            if(tmp > 0)
            {
                while(tmp--) cout << "(";
            }
            else 
            {
                tmp = -1*tmp;
                while(tmp--) cout << ")";
            }
            if(i+1 < s.size()-1)
            cout << s[i+1];
        } 
        cout << endl;
    }

    return 0;
} 