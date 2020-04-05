#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

bool parity(ll x) 
{ 
    int y = x ^ (x >> 1); 
    y = y ^ (y >> 2); 
    y = y ^ (y >> 4); 
    y = y ^ (y >> 8); 
    y = y ^ (y >> 16); 

    if (y & 1) 
        return 1; 
    return 0; 
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

    while(t--)
    {
    	ll odd=0,even=0,q,tmp,n;
        cin >> n >> q;
        vector<int> v(n);

        for(int i=0 ; i<n ; ++i) { cin >> v[i];
        		if(parity(v[i])) ++odd;
        		else ++even;
        	}
        for(int i=0 ; i<q ; ++i) { cin >> tmp;
        	if(parity(tmp)) cout << odd << " " << even << "\n";
        	else cout << even << " " << odd << "\n";
        }
    }

    return 0;
} 