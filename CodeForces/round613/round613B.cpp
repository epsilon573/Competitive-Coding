#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

bool bubbleSort(vector<int> &v, int n,vector<int> &chk)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (v[j] > v[j+1])  
        {
            swap(v[j], v[j+1]);
            if(chk[j]==0) return 0;  
        }
    return 1;    
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
    	ll m,n,tmp,flag=0;
    	cin >> n >> m;
    	vector<int> v(n),chk(n);
    	for(int i=0 ; i<n ; i++) cin >> v[i];
    	for(int i=0 ; i<m ; i++) {cin >> tmp; chk[tmp-1]=1;}
    	if(bubbleSort(v,n,chk)) cout << "YES" << endl;
    	else cout << "NO" << endl;	
    }

    return 0;
} 