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
    
    set<ll> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 21, 22, 23, 32, 33, 34, 43, 44, 45, 54, 55, 56, 65, 66, 67, 76, 77, 78, 87, 88, 89, 98, 99};

    ll cnt = 0 ,k;
    cin >> k;
    for(ll i=1 ; ; ++i)
    {
    	ll j=i,flag=1;
    	while(j>0)
    	{
    		if(find(v.begin(),v.end(),j%100)==v.end())
    		{	flag = 0; break; }
    		j/=10;
    	}

        if(flag) ++cnt;
        if(cnt == k) { cout << i ; return 0; } 
    }

    return 0;
} 