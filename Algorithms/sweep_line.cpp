#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

/*
bool mycompare( pair<ll,ll> pr1 , pair<ll,ll> pr2 )
{
	return ( pr1.x < pr2.x );
} */

struct setcompare
{
	bool operator () ( const pair<ll,ll> &pr1 , const pair<ll,ll> &pr2 )
	{
		return ( pr1.y < pr2.y );
	}
};

double dist( pair<ll,ll> pr1 , pair<ll,ll> pr2 )
{
	return( sqrt( (pr1.x-pr2.x)*(pr1.x-pr2.x) + (pr1.y-pr2.y)*(pr1.y-pr2.y) ) );
}

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

    ll n,px,py,left=0;
    double best = INT_MAX;
    cin >> n;

    pair<ll,ll> pnts[n];
    set< pair<ll,ll> , setcompare > ans;
    
    for(ll i=0 ; i<n ; ++i) { cin >> px >> py; pnts[i] = mp(px,py); }
    	sort(pnts,pnts+n);
    // for(ll i=0 ; i<n ; ++i) { cout <<  pnts[i].x << " " <<  pnts[i].y << endl; }
    
    
    ans.insert(pnts[0]);
    
    for(int i=1 ; i<n ; ++i)
    {
        while(left<i && (pnts[i].x-pnts[left].x)>best) { ans.erase(pnts[left++]); }
        
        for(auto it = ans.lower_bound( mp(pnts[i].x-best,pnts[i].y-best) ) ; 
        	it!=ans.end() && it->y <= pnts[i].y + best ;
        	++it ) { 
                    best = min(best, dist(*it,pnts[i])); 
                    }
        ans.insert(pnts[i]);            
    }
    
    cout << best;
    return 0;
} 