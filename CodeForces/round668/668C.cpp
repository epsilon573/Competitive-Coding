// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

bool solve()
{
    ll n,k;
    cin >> n >> k;

    string s; 
    cin >> s;

    ll ques = count(s.begin(),s.end(),'?');

    if(ques == n) return true;
    
    for(ll i=0 ; i<n ; ++i)
        {
            if(s[i]=='1')
            {
                if(i-k >=0 )
                {
                    if(s[i-k]=='0') return false;
                    else s[i-k]='1';
                }
                if(i+k < n )
                {
                    if(s[i+k]=='0') return false;
                    else s[i+k]='1';                    
                }
            }
        }

    for(ll i=0 ; i<n ; ++i)
    {
            if(s[i]=='0')
            {
                if(i-k >= 0 )
                {
                    if(s[i-k]=='1') return false;
                    else s[i-k]='0';
                }
                if(i+k < n )
                {
                    if(s[i+k]=='1') return false;
                    else s[i+k]='0';                    
                }
            }        
    }

    ll tmpq = count(s.begin(),s.begin()+k,'?');
    ll tmpz = count(s.begin(),s.begin()+k,'0');
    ll tmpo = count(s.begin(),s.begin()+k,'1');
    
    if( abs(tmpz-tmpo) > tmpq ) return false;

    for(ll i=k ; i<n ; ++i)
    {
        if(s[i-k] == '1') tmpo--;
        if(s[i-k] == '0') tmpz--;
        if(s[i-k] == '?') tmpq--;

        if(s[i] == '1') tmpo++;
        if(s[i] == '0') tmpz++;
        if(s[i] == '?') tmpq++;
        
        if( abs(tmpz-tmpo) > tmpq ) return false;
    }
    
    return true;    
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

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
} 