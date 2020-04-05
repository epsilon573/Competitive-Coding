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

    ll t,a,b,c,d,x,y,x1,y1,x2,y2;
    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        

        ll mxmleft = x - x1, mxmright = x2 - x , mxmup = y2 - y , mxmdwn = y - y1;

        if( (b!=0 || a!=0) && (mxmleft==0 && mxmright==0) )
        	{ 
        		cout << "No" << endl; 
        	    continue; 
        	}
        if( (c!=0 || d!=0) && (mxmup==0 && mxmdwn==0) )
        	{
        		cout << "No" << endl; 
        	 	continue; 
        	}

        if( 
        	( ( b>=a ) && mxmright >= (b-a) || ( a>=b ) && mxmleft >= (a-b) )
                                          &&
            ( ( d>=c ) && mxmup >= (d-c) || ( c>=d ) && mxmdwn >= (c-d) )                               
          )
        	{ 
        		cout << "Yes" << endl;
        		continue;
        	 }
        else 
        	cout << "No" << endl;

    }

    return 0;
} 