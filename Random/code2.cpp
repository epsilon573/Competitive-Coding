#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

bool checkleap(ll y)
{
    if(y%400==0)
    	return true;
    else if(y%100==0)
    	return false;
    else if(y%4==0)
    	return true;
    else
    	return false;
}

bool day(ll y)
{
  ll yt = y;
  y -= 1 < 3;
  int n = (y + y/4 - y/100 + y/400 + 1) % 7;
    
    if(n==3)
		return true;
    if(n==4 && !checkleap(yt))
		return true;
    else
		return false;
}

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
    vector<int> dp(100000);
    dp[0]=0;
    for(int i=1 ; i<100000 ; ++i)
    {
       	if(day(i))
       		dp[i] = dp[i-1]+1;
        else
            dp[i] = dp[i-1];
    }    
    while(t--)
    {
        ll m1,y1,m2,y2;
        cin >> m1 >> y1 >> m2 >> y2;
        if(m1<=2 && m2>=2)
        {
        	cout << dp[y2]-dp[y1-1] << endl;
        }
        else if(m1>2 && m2>=2)
        {
        	cout << dp[y2]-dp[y1] << endl;
        }
        else if(m1>2 && m2<2)
        {
        	cout << dp[y2-1]-dp[y1] << endl;
        }
        else if(m1<=2 && m2<2)
        {
        	cout << dp[y2-1]-dp[y1-1] << endl;
        }
    }

    return 0;
} 