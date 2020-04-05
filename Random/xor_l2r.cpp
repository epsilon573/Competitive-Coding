#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

ll countBits(ll n) 
{ 
   ll count = 0; 
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
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

    ull t,l,r,ans=0,max_bits;
    cin >> t;

    while(t--)
    {
       cin >> r >> l;
       max_bits = countBits(r);

       ll i;
       for(i=max_bits-1 ; i>=0 ; --i)
       {
       	   // cerr << i << " " << ((l>>i)&1) << " " << ((r>>i)&1);
       	   if( ((l>>i)&1)==0 && ((r>>i)&1)==1 ) 
       	   { break; }
       }

       for(ll j=0 ; j<=i ; j++) ans |= (1<<j);
       cout << ans << endl;

    }

    return 0;
} 