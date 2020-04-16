#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 2e5+1;
const ll inf = LLONG_MAX;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

vector<ll> v(maxn),answers(maxn);
ll answer = 0, block_size;
ll freq[1000001];

struct query
{
    ll l,r,idx;
    
    query(ll _l , ll _r , ll _idx) : l(_l) , r(_r) , idx(_idx) {} 

    bool operator < (const query& myquery)
    {
        if(l/block_size != myquery.l/block_size)
        return l/block_size < myquery.l/block_size;
        else
        return (l/block_size & 1) ? myquery.r < r : r < myquery.r ;           
    }
};


void add(ll index)
{
    answer += (2*freq[ v[index] ]+1)*v[index];
    freq[ v[index] ]++;
}

void remove(ll index)
{
    answer += (1-2*freq[ v[index] ])*v[index];
    freq[ v[index] ]--; 
}

void mos_algo( const vector<query>& queries )
{
    ll cur_l = 0, cur_r = -1;
    
    for(auto x : queries)
    {
        while (cur_l > x.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < x.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < x.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > x.r) {
            remove(cur_r);
            cur_r--;
        }

        answers[x.idx] = answer;
    }
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

    ll n,q;
    cin >> n >> q;
    block_size = sqrt(n)+1;
    vector<query> queries;

    for(ll i=0 ; i<n ; ++i) cin >> v[i];
    
    for(ll i=0 ; i<q ; ++i)
    {
        ll l,r;
        cin >> l >> r ; 
        l--,r--;
        queries.pb( query( l , r, i) );
    }
    
    sort( queries.begin() , queries.end() );
    mos_algo( queries );
    
    for(ll i=0 ; i<q ; ++i) cout << answers[i] << endl;

    return 0;
} 