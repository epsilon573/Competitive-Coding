#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

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

    ll t,s,tmp,n;
    cin >> t >> s;
    if(s==1) {
    while(t--)
    {
       int flag=0,max=0;
       cin >> n;
       priority_queue<int, vector<int>, greater<int>> a,b;
       set<int> table;
       for(int i=0 ; i<n ; ++i) { cin >> tmp; a.push(tmp); }
       for(int i=0 ; i<n ; ++i) { cin >> tmp; b.push(tmp); }
       
       table.insert(a.top());

       for(int i=0 ; i<n ; ++i) {
       	if(a.top() < b.top() && table.find(a.top())!=table.end() )
        { table.insert(a.top()); table.insert(b.top()); a.pop(); b.pop(); }
       	else { flag=1; break; } 
       }
       if(flag==1) { cout << "NO" << endl; }
       else { cout << "YES" << endl; }
    } } 
    return 0;
} 