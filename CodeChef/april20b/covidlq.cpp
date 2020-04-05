#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

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
       ll n;
       cin >> n;
       string str = "YES";
       vector<ll> v;
       for(ll i=0,tmp ; i<n ; ++i)
       {
       	   cin >> tmp;
       	   if(tmp==1) { v.pb(i); }
       } 

       for(ll i=0 ; i<v.size()-1 ; ++i)
       { 
           if(v[i+1]-v[i]<6) 
           {
           	   str="NO";
           	   break;
           }
       }

       cout << str << endl;
    }

    return 0;
} 