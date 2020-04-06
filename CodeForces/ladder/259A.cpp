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

    string s1="BWBWBWBW",s2="WBWBWBWB";

    for(ll i=0 ; i<8 ; ++i)
    {
        string s;
        cin >> s;
        if(s!=s1 && s!=s2) { cout << "NO"; return 0; }
    }

    cout << "YES";
    return 0;
} 