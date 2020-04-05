#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;
const ll alpha_size = 26;

#define mp make_pair
#define pb push_back

#define deb(x) cout << #x << " " << x << endl

struct trie
{
	struct trie* node[alpha_size];
	bool endofstring;
};

struct trie* createNode()
{
    struct trie* newTrie = new trie;
    for(ll i=0 ; i<alpha_size ; ++i)
    {
        newTrie->node[i] = NULL;
    }
    newTrie->endofstring = false;
    return newTrie;
};

void insertTrie(struct trie* root , string s)
{
    struct trie* curr = root;
    for(ll i=0 ; i<s.size() ; ++i)
	{
		ll idx = s[i]-'a';
        if(!curr->node[idx])
          curr->node[idx] = createNode();
        curr = curr->node[idx];
	}	
	curr->endofstring = true;
}

bool searchTrie(struct trie* root, string s)
{
	struct trie* curr = root;
	for(ll i=0 ; i<s.size() ; ++i)
	{
		ll idx = s[i]-'a';
        if(!curr->node[idx]) return false;
        curr = curr->node[idx];
	}	
	return curr->endofstring;

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


    struct trie* rootTrie = createNode(); 

    ll n; string s;
    cin >> n;
    
    while(n--)
    {
    	cin >> s;
    	insertTrie(rootTrie , s);
    }

    cin >> s;
    if(searchTrie(rootTrie, s)) cout << s << " exists" ;
    else cout << s << " not found";

    return 0;
} 