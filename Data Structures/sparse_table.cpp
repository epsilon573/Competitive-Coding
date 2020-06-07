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

vector<vector<int>> st1, st2;
vector<int> ans;

bool check(int k, int n)
{
    for(int i=0 ; i+k <= n ; ++i)
    {
        int len = log2(k);
        int query1 = min( st1[len][i] , st1[len][ i+k- (1 << len)] );
        int query2 = __gcd( st2[len][i] , st2[len][ i+k- (1 << len)] );

        if( query1 == query2 ) return true; 
    }
    
    return false;
}

int getcnt(int k, int n)
{
    int cnt = 0;
    ans.clear();
    for(int i=0 ; i+k <= n ; ++i)
    {
        int len = log2(k);
        int query1 = min( st1[len][i] , st1[len][ i+k- (1 << len)] );
        int query2 = __gcd( st2[len][i] , st2[len][ i+k- (1 << len)] );

        if( query1 == query2 ) 
        {
            ++cnt; ans.pb(i+1);
        }
    }
    
    return cnt;
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

    int n;
    cin >> n;

    vector<int> v(n);

    for(ll i=0 ; i<n ; ++i)
    cin >> v[i];

    st1.resize( (int)log2(n)+1 , vector<int> (n,-1));
    st2.resize( (int)log2(n)+1 , vector<int> (n,-1));
    
    for(ll i=0 ; i<n ; ++i)
    st1[0][i] = st2[0][i] = v[i];

    for(ll i=1 ; i < (int)log2(n)+1 ; ++i)
    {
        for(ll j=0 ; (j + (1 << i)) <= n ; ++j)
        {
            st1[i][j] = min( st1[i-1][j] , st1[i-1][ j + ( 1 << (i-1) )] );
            st2[i][j] = __gcd( st2[i-1][j] , st2[i-1][  j + ( 1 << (i-1) ) ]); 
        }
    }

    int l = 1 , r = n , mid;

    while( l<r )
    {
        mid = (l+r+1)/2;
        
        if( check(mid,n) )
            l = mid;
        else 
            r = mid - 1;
    }

    int cnt = getcnt(l,n);

    cout << cnt << " " << l-1 << endl;
    for(auto x : ans) cout << x << " ";

    return 0;
} 