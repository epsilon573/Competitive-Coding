#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

void solve()
{
   cout << 7 << " " << 7 << endl;
   cout << 6 << " " << 8 << endl;
   cout << 1 << " " << 3 << endl;
   cout << 3 << " " << 1 << endl;
   cout << 7 << " " << 5 << endl;
   cout << 4 << " " << 8 << endl;
   cout << 1 << " " << 5 << endl;
   cout << 5 << " " << 1 << endl;
   cout << 7 << " " << 3 << endl;
   cout << 2 << " " << 8 << endl;
   cout << 1 << " " << 7 << endl;
   cout << 7 << " " << 1 << endl;
   cout << 8 << " " << 2 << endl;
   cout << 7 << " " << 3 << endl;
   cout << 8 << " " << 4 << endl;
   cout << 7 << " " << 5 << endl;
   cout << 8 << " " << 6 << endl;
   cout << 7 << " " << 7 << endl;
   cout << 8 << " " << 8 << endl;
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

    ll t,r,c;
    cin >> t;

    while(t--)
    {
        cin >> r >> c;
        if(r==1 && c==1) {
        	cout << "19" << endl;
            solve(); }
        else if(r==c) {
            cout << "20" << endl;
            cout << 1 << " "<< 1 << endl;
            solve(); }
        else {
        	cout << "21" << endl;
        	cout << (r+c)/2 << " " << (r+c)/2 << endl;
        	cout << 1 << " " << 1 << endl;
        	solve();
        }       
    }

    return 0;
} 