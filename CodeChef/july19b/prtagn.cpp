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

    ll t,n,q;
    cin >> t;

    while(t--)
    {
        set<ll> s;
    	ll e=0,o=0;
    	cin >> q;
    	while(q--)
    	{
            cin >> n;
            
            if(s.find(n) != s.end())
            {
                cout << e << " " <<o <<"\n";
                continue;
            }

            set<ll> t;

            for(auto it=s.begin() ; it!=s.end() ; it++)
            {
                ll y=*it;
                
                if(__builtin_popcount(n^y)%2)
                    o++;
                else
                    e++;
                t.insert(n^y);
            }

            for(auto it=t.begin() ; it!=t.end() ; it++)
            {
                s.insert((*it));
            }
            s.insert(n);

            if(__builtin_popcount(n)%2)
                o++;
            else
                e++;
            cout << e << " " << o << "\n";
    	}
    }

    return 0;
} 