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

    ll t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        
        map<char,int> m;
        m['1'] = 0; m['2']=0; m['3']=0;
        bool ans = false;
        int len = s.size() , start = 0 , end = 0;

        m[s[0]]++;

        while(1)
        {
            if(m['1'] && m['2'] && m['3'])
            {
                ans = true;
                len = min(len, end-start+1);
                m[s[start]]--;
                start++;
            }
            else
            {
                if(end == s.size()-1) break;
                end++;
                m[s[end]]++;
            }
        }

        if(ans) cout << len << endl;
        else cout << 0 << endl;

    }

    return 0;
} 