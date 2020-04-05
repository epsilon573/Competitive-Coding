#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1e9+7
#define eps 1e-9 

#define mp make_pair
#define pb push_back

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

    ll t,idx,h_idx;
    cin >> t;
 
    set<pair<ll,ll>> s;
    
    for(int i=0 ; i<10 ; ++i)
    {
    	cin >> idx;
    	for(int j=0 ; j<9 ; ++j) 
    		{ 
    			cin >> h_idx; 
    			s.insert( mp( min(idx,h_idx) , max(idx,h_idx) ) ); 
    		}
    }

    cout << t*(t-1)/2 - s.size();

    return 0;
} 