#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

ll cnt = 0;

string query(ll x,ll y)
{
    cout << x << " " << y << endl;
    cout.flush();
    string s;
    cin >> s;
    
    ++cnt;
    assert( cnt < 300 );
    assert( s!="WRONG" );

    return s;
}

void solve()
{

    ll req_x, req_y;

    for(ll i=-4 ; i<=4 ; ++i)
        {
            for(ll j=-4 ; j<=4 ; ++j)
            {
                ll x = i*( (ll)1e9/4 );
                ll y = j*( (ll)1e9/4 );

                string q = query(x,y);

                if(q == "HIT") 
                { 
                    req_x = x , req_y = y; 
                } 

                if(q == "CENTER")
                    return;
            }
        }

        ll left_x , right_x , upper_y , lower_y;
        
        ll lower = (ll)-1e9 , upper = req_x;
        while(lower < upper)
        {
            ll mid  = (lower+upper-1)/2;
            string q = query( mid , req_y);
            if( q == "MISS" )
                lower = mid+1;
            else if( q == "HIT" )
                upper = mid;
            else if( q == "CENTER" )
                return;
            else return;
        }
        left_x = lower;

        lower = req_x , upper = (ll)1e9;
        while(lower < upper)
        {
            ll mid  = (lower+upper+1)/2;
            string q = query( mid , req_y);
            if( q == "MISS" )
                upper = mid-1;
            else if( q == "HIT" )
                lower = mid;
            else if( q == "CENTER" )
                return;
            else return;
        }
        right_x = lower;

        lower = (ll)-1e9 , upper = req_y;
        while(lower < upper)
        {
            ll mid  = (lower+upper-1)/2;
            string q = query( req_x , mid);
            if( q == "MISS" )
                lower = mid+1;
            else if( q == "HIT" )
                upper = mid;
            else if( q == "CENTER" )
                return;
            else return;
        }
        lower_y = lower;

        lower = req_y , upper = (ll)1e9;
        while(lower < upper)
        {
            ll mid  = (lower+upper+1)/2;
            string q = query( req_x , mid);
            if( q == "MISS" )
                upper = mid-1;
            else if( q == "HIT" )
                lower = mid;
            else if( q == "CENTER" )
                return;
            else return;
        }
        upper_y = lower;

        string q = query( (left_x+right_x)/2 , (lower_y+upper_y)/2 );
        assert( q == "CENTER" );
        return;

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t,a,b;
    cin >> t >> a >> b;

    while(t--)
    {
        cnt = 0;
        solve();
    }

    return 0;
} 