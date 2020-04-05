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

    int t;
    cin >> t;

    while(t--)
    {
    	int sum = 0,a,b;
          
        cin >> a >> b;

        if(a<10 && b<10) sum = a+b;
        else if(a>=10 && b>=10)
        {
            sum = max(sum , a+b);
            sum = max(sum , a/10*10+b/10+a%10*10+b%10);
            sum = max(sum , b%10*10+a/10+b/10*10+a%10);
        }
        else
        {
        	if(b>a) swap(a,b);
        	sum = max(sum , a+b);
        	sum = max(sum , b%10*10+a/10+b/10*10+a%10);
        }
        cout << sum << endl;
    }

    return 0;
} 