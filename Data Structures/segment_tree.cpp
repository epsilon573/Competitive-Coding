#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 1000000007
#define maxn 100001

ll tree[4*maxn],arr[maxn],lazy[4*maxn];

// Update Lazy Leftovers if Required

ll push(ll node)
{
  lazy[2*node] += lazy[node];
  tree[2*node] += lazy[node];

  lazy[2*node + 1] += lazy[node];
  tree[2*node + 1] += lazy[node];

  lazy[node] = 0;  

  return 0;
}

// Build Segment Tree

ll build(ll node, ll start, ll end)
{
    if(start==end) { tree[node] = arr[start]; return 0;}
    else 
    {
        ll mid = (start+end)/2;
        build(2*node, start , mid);
        build(2*node+1, mid+1 , end); 
    }
    tree[node] = min(tree[2*node],tree[2*node+1]);
    return 0;
}

// For Point Updates

ll update(ll node, ll start, ll end, ll idx, ll val)
{
   if(start==end)
   {
   	   arr[idx] = val;
   	   tree[node] = val;
   	   return 0;
   }
   else
   {
       ll mid = (start+end)/2;
       if(idx<=mid) update(2*node, start, mid, idx, val);
       else update(2*node+1, mid+1, end, idx, val);
   }
    tree[node] = min(tree[2*node],tree[2*node+1]);
    return 0;

}

// For Range Updates

ll update_range(ll node, ll start, ll end, ll l , ll r, ll val)
{
   if(start==l && end==r)
   {
       lazy[node] += val;
       tree[node] += val;
   }
   else
   {
       if(lazy[node]!=0) push(node);
       ll mid = (start+end)/2;
       
       if( l>=start && r<=mid ) update_range(2*node, start, mid, l, r, val);
       else if( l>mid && r<=end ) update_range(2*node+1, mid+1, end, l, r, val);
       else 
       {  
          update_range(2*node , start , mid , l , mid , val);
          update_range(2*node + 1, mid+1 , end, mid+1 , r , val);
       }

       tree[node] = max(tree[2*node],tree[2*node+1]);
   }
    
    return 0;

}

// For Range Query

ll query(ll node, ll start, ll end, ll l , ll r)
{
    if(start == l && end == r) return tree[node];
    else
    {
      if(lazy[node]!=0) push(node);

    	ll mid = (start+end)/2;
    	if(l>=start && r<=mid) return query(2*node,start,mid,l,r);
    	else if(l>mid && r<=end) return query(2*node+1,mid+1,end,l,r);
    	else return min(query(2*node,start,mid,l,mid),query(2*node+1,mid+1,end,mid+1,r));
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

    ll t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(ll i=0 ; i<n ; i++) cin >> arr[i];

        memset(lazy , 0 , sizeof(lazy));
        build(1,0,n-1);

        cout << query(1,0,4,1,1) << endl;
        cout << query(1,0,4,3,3) << endl;
        cout << query(1,0,4,1,2) << endl;
        cout << query(1,0,4,2,3) << endl;
        cout << query(1,0,4,1,3) << endl;
        cout << query(1,0,4,2,4) << endl;
        cout << query(1,0,4,0,3) << endl;
        cout << query(1,0,4,1,4) << endl;
        cout << query(1,0,4,0,4) << endl;
    }

    return 0;
} 