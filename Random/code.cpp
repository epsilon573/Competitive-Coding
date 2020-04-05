#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

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

    ll t,n,k,sum,ans=0;
    cin >> t;

    while(t--)
    {
    	ll temp,cost,sum = INT_MIN;
    	char c;
    	cin >> n;
    	vector<vector<int>> v(4, vector<int> (13));
    	vector<int> time{3,6,9,12},res(4);
    	for(int i=0 ; i<n ; i++) { cin >> c >> temp; ++v[c-'A'][temp]; }
    	//for(int i=0 ; i<4 ; i++) {for(int j=1 ; j<5 ; j++) cout << v[i][3*j] << " " ; cout << endl;}	
    	do{
    		temp = 0,cost=25;
    		res[0]=v[0][time[0]];
    		res[1]=v[1][time[1]];
    		res[2]=v[2][time[2]];
            res[3]=v[3][time[3]];
            sort(res.begin(),res.end());

            for(int i=0 ; i<4 ; i++,cost+=25)
            {
                if(res[i]==0)
                	temp -= 100;
                else temp += res[i]*cost;
            }
            sum = max(temp,sum);
            /* for(auto it:time) cout << it << " ";
            	cout << sum << endl; */
    	}while(next_permutation(time.begin(),time.end()));
    	ans += sum;
    	cout << sum << endl;
    }
    cout << ans ;
    return 0;
} 