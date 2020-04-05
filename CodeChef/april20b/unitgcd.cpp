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

    ll t,n;
    cin >> t;
     
    while(t--)
    {
        cin >> n;

        if(n==1) cout << 1 << endl << "1 1" << endl;
        else if(n==2) cout << 1 << endl <<  "2 1 2" << endl;
        else if(n==3) cout << 1 << endl << "3 1 2 3" << endl;
        else
        {
        	cout << n/2 << endl << "3 1 2 3" << endl;
        	for(ll i=2 ; i<=n/2 ; ++i)
        	{
        		if(2*i+1<=n)
                cout << 2 << " " << 2*i << " " << 2*i+1 << endl; 
                else
                cout << 1 << " " << 2*i << endl; 
        	}
        }
      

        
    }

    return 0;
} 