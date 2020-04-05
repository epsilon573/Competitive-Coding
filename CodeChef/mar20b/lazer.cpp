#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007

#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007
#define maxn 100001

ll tree[4*maxn],v[maxn],qi[maxn],ql[maxn],qr[maxn];

// Using Sweep Line + Segment Tree (For Queries)
// Answer Queries Offline

// Event For Sweep Line

struct event
{
    ll y;
    ll type; // 1 - Add Line , 2 - Query , 3 - Remove Line
    ll id;
    event(ll _y, ll _type, ll _id) : y(_y),type(_type),id(_id) {}
};

bool event_cmp(const event& a, const event& b)
{
    if(a.y == b.y) return a.type < b.type;
    else return a.y < b.y;
}

// Line Update

ll update(ll node, ll start, ll end, ll idx, ll val)
{
   if(start==end)
   {
       tree[node] = val;
       return 0;
   }
   else
   {
       ll mid = (start+end)/2;
       if(idx<=mid) update(2*node, start, mid, idx, val);
       else update(2*node+1, mid+1, end, idx, val);
   }
    tree[node] = tree[2*node]+tree[2*node+1];
    return 0;

}

// For Range Query

ll query(ll node, ll start, ll end, ll l , ll r)
{
    if(start == l && end == r) return tree[node];
    else
    {
        ll mid = (start+end)/2;
        if(l>=start && r<=mid) return query(2*node,start,mid,l,r);
        else if(l>mid && r<=end) return query(2*node+1,mid+1,end,l,r);
        else return query(2*node,start,mid,l,mid)+query(2*node+1,mid+1,end,mid+1,r);
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

	ll t,cnt,n,q;
    cin >> t; 
    
    while(t--)
    {
        cin >> n >> q;
        vector<event> ve;
        vector<ll> ans(q);
        for(int i=0 ; i<n ; ++i) { cin >> v[i]; }
        for(int i=0 ; i<q ; ++i) { cin >> ql[i] >> qr[i] >> qi[i]; }    
         
        for(int i=0 ; i<n-1 ; ++i)
        {
            ve.push_back( event( min(v[i],v[i+1]) , 1 , i ) );
            ve.push_back( event( max(v[i],v[i+1]) , 3 , i ) );
        }

        for(int i=0 ; i<q ; ++i)
        {
            ve.push_back( (event( qi[i] , 2 , i)) );
        }
     
        sort(ve.begin(),ve.end(),event_cmp);
        
        for(auto it=ve.begin() ; it!=ve.end() ; ++it)
        {
            if(it->type==1) update(1,0,n-2,it->id,1);
            else if(it->type==3) update(1,0,n-2,it->id,0);
            else 
            {
                ll qid = it->id;
                ans[qid] = query(1,0,n-2,ql[qid]-1,qr[qid]-2);
            } 
        }       
        
        for(ll i=0 ; i<q ; ++i) cout << ans[i] << endl;
    }

    return 0; 
} 