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
    ll n,k,cnt=0,ans=0,ini=0,last=0;
    cin >> n >> k;

    string v; cin >> v;

    for(ll i=0 ; i<n ; ++i)
    {
        if( i<n && v[i]=='W' )
        {
            while(v[i]=='W')
                ++cnt,++i;
            
            ans += (cnt-1)*2 + 1;
            cnt = 0;
        } 
    }
    
    if(cnt!=0) ans += (cnt-1)*2 + 1;
    
    if(k==0) 
    {
        cout << ans << endl;
        return true;
    }
    if(ans==0)
    {
       ans += 2*(k-1)+1;
       cout << ans << endl;
       return true;
    }

    vector<ll> len;
    
    if(v[0]=='W') len.pb(0);

    for(ll i=0 ; i<n ; ++i)
    {
        if( i<n && v[i]=='L' )
        {
            while(v[i]=='L')
                ++cnt,++i;
            
            if(i>=n) break;

            len.pb(cnt);
            cnt = 0;
        } 
    }

    sort(len.begin()+1,len.end());

    for(ll i=1 ; i<len.size() && k>0 ; ++i)
    {
        if(k>=len[i])
        {   
            ans += 2*len[i]+1;
            k -= len[i];
        }
        else
        {
           
            ans += 2*k;  k=0;
        }
    }
    
    last = cnt;
    if(last==0) NULL;
    else
    {
        if(k>=last)
        {   
            ans += 2*last;
            k -= last;
        }
        else
        {
            ans += 2*k;
            k =0 ;
        }
    }

    if(len[0]==0) NULL;
    else
    {
        if(k>=len[0])
        {   
            ans += 2*len[0];
            k -= len[0];
        }
        else
        {
            
            ans += 2*k; k=0;
        }
    }

    cout << ans << endl;    
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
            // do this;
        }
        else
        {
            // do this;
        }
    }

    return 0;
} 