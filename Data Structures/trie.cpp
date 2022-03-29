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
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

// Base Character and Alphabet Size
char base = 'a';
ll alpha = 26;

// Information about Node
struct Node{
    ll ending_here;
    ll passing_here;    
    vector<ll> idx;

    Node(){
        idx.assign(alpha,-1);
        ending_here = 0;
        passing_here = 0;
    }

    ll& operator[](ll x){
        return idx[x];
    }
};

struct Trie{
    vector<Node> v;

    Trie(){
        v.emplace_back();
    }

    void insertString(string s){
        ll curr_idx = 0;
        v[curr_idx].passing_here++;

        for(auto c : s)
        {
            if(v[curr_idx][c-base]==-1)
            {
                v.emplace_back();
                v[curr_idx][c-base] = (ll)v.size() - 1;
            }

            curr_idx = v[curr_idx][c-base];
            v[curr_idx].passing_here++;
        }

        v[curr_idx].ending_here++;        
    }

    // Query Trie
    // Example - Count strings with given prefix
    ll countStringsWithPrefix(string s){
        ll curr_idx = 0;
        for(auto c : s)
        {
            if(v[curr_idx][c-base]==-1)
            {
                return 0;
            }
            else
                curr_idx = v[curr_idx][c-base];
        }
        return v[curr_idx].passing_here;
    }

    // Example - Count Longest Common Prefix
    string longestCommonPrefix(ll n){
        string res = "";
        ll curr_idx = 0;

        while(1){
            ll found = false;
            for(ll i=0 ; i<alpha ; ++i)
                if(v[v[curr_idx][i]].passing_here==n)
                {
                    res.pb(base+i);
                    curr_idx = v[curr_idx][i];
                    found = true;
                    break;
                }

            if(!found)
                break;
        }
        return res;
    }
};

bool solve()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    Trie t;

    for(ll i=0 ; i<n ; ++i){
        cin >> v[i];
        t.insertString(v[i]);
    }

    cout << t.longestCommonPrefix(n);
    
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;

    while(t--)
    {
        if(solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 