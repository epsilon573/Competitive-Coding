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
#define deb(x) cerr << #x << " " << x << endl

ll n,k;
bool cant[2001][2001];
string num[] = { "1110111", "0010010", "1011101", "1011011", "0111010", 
            "1101011", "1101111", "1010010", "1111111", "1111011" }, str[2001]
            , ans = "" ;

string sor(string& str1 , string& str2)
{
    string res="";
    for(ll i=0 ; i<str1.size() ; ++i)
    {
        if( str1[i]=='1' || str2[i]=='1') res += "1";
        else res += "0";
    }
    return res;
}

bool solve(int str_idx , int bits)
{

    for(int i=9 ; i>=0 ; --i)
    {
        if( sor(str[str_idx],num[i]) == num[i] )
        {    
            ll cost =  count(num[i].begin(),num[i].end(),'1') - count(str[str_idx].begin(),str[str_idx].end(),'1');

            if(cost > bits || cant[str_idx+1][ bits - cost] ) continue;

            if(str_idx == n-1)
            {
                if(cost == bits)
                {
                    ans += '0'+i;
                    return true;
                }    
                else
                    continue;
            }
            
            if( solve( str_idx + 1 , bits - cost) )
            {
                ans += '0'+i;
                return true;
            }
        }
    }
    
    cant[str_idx][bits] = true;
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

    cin >> n >> k;

    for(ll i=0 ; i<n ; ++i) cin >> str[i];

    if(solve(0,k)) {    
    reverse(ans.begin(),ans.end());
    cout << ans;    
    }
    else
    cout << -1 ;

    return 0;
} 