#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

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

    ll t,k,x;
    cin >> t;

    while(t--)
    {
    	string s;
        cin >> s;
        cin >> k >> x;

        ll cnt[26]={0},ans=0;

        ll i=0;
        for(i=0 ; i<s.size() ; ++i)
        {
            if(++cnt[s[i]-'a']>x)
            {
            	if(k==0) break;
            	k--;
            }
            else
            ++ans;
        }
        cout << ans << endl;
    }

    return 0;
} 