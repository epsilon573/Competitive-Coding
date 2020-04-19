#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

struct dir
{
    ll north, east, west, south;
    dir(ll _n , ll _e , ll _w , ll _s) : north(_n), east(_e), west(_w), south(_s) {}
};

dir add (const dir& dir1, const dir& dir2)
{
    return dir( (dir1.north+dir2.north)%mod , (dir1.east+dir2.east)%mod , (dir1.west+dir2.west)%mod , (dir1.south+dir2.south)%mod )  ;
}

dir mul (const ll m, const dir& dir2)
{
    return dir( (m*dir2.north)%mod , (m*dir2.east)%mod , (m*dir2.west)%mod , (m*dir2.south)%mod )  ;
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

    for(ll i=1 ; i<=t ; ++i)
    {
        cout << "Case #" << i << ": ";
        string s;
        cin >> s;

        stack<int> numbers;
        stack<char> characters;
        stack<dir> directions;

        for(ll i=0 ; i<s.size() ; ++i)
        {
           
            if( s[i] >= '1' && s[i] <= '9') numbers.push(s[i]-'0'); 
            else if( s[i] == '(') characters.push( s[i] );
            else if( s[i] == ')' )
            {
                char c = characters.top();
                characters.pop();
                
                dir ans = dir(0,0,0,0);

                while(c!='(')
                {
                    ans = add(ans,directions.top());
                    directions.pop();

                    c = characters.top();
                    characters.pop(); 
                }
                
                ll multiplier = numbers.top();
                numbers.pop();

                ans = mul( multiplier , ans );

                characters.push('#');
                directions.push(ans);    

            }
            else
            {
                    characters.push( '#' );
                    if(s[i] == 'N') directions.push( dir(1,0,0,0) );
                    if(s[i] == 'E') directions.push( dir(0,1,0,0) );
                    if(s[i] == 'W') directions.push( dir(0,0,1,0) );
                    if(s[i] == 'S') directions.push( dir(0,0,0,1) );
            }

        }
         

        dir ans = dir(0,0,0,0); 
        while( !directions.empty() )
        {
            dir hey = directions.top();
            directions.pop();

            ans = add(ans,hey);
        } 

        if(ans.east - ans.west >= 0) 
        cout << 1 + (ans.east-ans.west)%mod << " " ;
        else   
        cout << (ll)1e9 - (ans.west - ans.east - 1)%mod << " " ; 

        if(ans.south - ans.north >= 0) 
        cout << 1 + (ans.south-ans.north)%mod << endl ;
        else   
        cout << (ll)1e9 - (ans.north - ans.south - 1)%mod << endl ;

    }

    return 0;
} 