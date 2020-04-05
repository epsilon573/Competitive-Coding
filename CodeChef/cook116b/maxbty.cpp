#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 1e9+7;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back

ll tree1[400001],tree2[400001],sum[100001],lazy1[400001],lazy2[400001];

// Gives TLE , needs Lazy Propagation

// Segment Tree with Max Prefix Sum

ll push1(ll node)
{
  lazy1[2*node] += lazy1[node];
  tree1[2*node] += lazy1[node];

  lazy1[2*node + 1] += lazy1[node];
  tree1[2*node + 1] += lazy1[node];

  lazy1[node] = 0;  

  return 0;
}

ll build1(ll node, ll start, ll end)
{
    if(start==end) { tree1[node] = sum[start]; return 0;}
    else 
    {
        ll mid = (start+end)/2;
        build1(2*node, start , mid);
        build1(2*node+1, mid+1 , end); 
    }
    tree1[node] = max(tree1[2*node],tree1[2*node+1]);
    return 0;
}

ll query1(ll node, ll start, ll end, ll l , ll r)
{
    if(start == l && end == r) return tree1[node];
    else
    {
      if(lazy1[node]!=0) push1(node);

    	ll mid = (start+end)/2;
    	if(l>=start && r<=mid) return query1(2*node,start,mid,l,r);
    	else if(l>mid && r<=end) return query1(2*node+1,mid+1,end,l,r);
    	else return max(query1(2*node,start,mid,l,mid),query1(2*node+1,mid+1,end,mid+1,r));
    }

} 

ll update_range1(ll node, ll start, ll end, ll l , ll r, ll val)
{
   if(start==l && end==r)
   {
       lazy1[node] += val;
       tree1[node] += val;
   }
   else
   {
       if(lazy1[node]!=0) push1(node);
       ll mid = (start+end)/2;
       
       if( l>=start && r<=mid ) update_range1(2*node, start, mid, l, r, val);
       else if( l>mid && r<=end ) update_range1(2*node+1, mid+1, end, l, r, val);
       else 
       {  
          update_range1(2*node , start , mid , l , mid , val);
          update_range1(2*node + 1, mid+1 , end, mid+1 , r , val);
       }

       tree1[node] = max(tree1[2*node],tree1[2*node+1]);
   }
    
    return 0;

}

// Segment Tree with Min Prefix Sum

ll push2(ll node)
{
  lazy2[2*node] += lazy2[node];
  tree2[2*node] += lazy2[node];

  lazy2[2*node + 1] += lazy2[node];
  tree2[2*node + 1] += lazy2[node];

  lazy2[node] = 0;  

  return 0;
}

ll build2(ll node, ll start, ll end)
{
    if(start==end) { tree2[node] = sum[start]; return 0;}
    else 
    {
        ll mid = (start+end)/2;
        build2(2*node, start , mid);
        build2(2*node+1, mid+1 , end); 
    }
    tree2[node] = min(tree2[2*node],tree2[2*node+1]);
    return 0;
}


ll query2(ll node, ll start, ll end, ll l , ll r)
{
    if(start == l && end == r) return tree2[node];
    else
    {
      if(lazy2[node]!=0) push2(node);

    	ll mid = (start+end)/2;
    	if(l>=start && r<=mid) return query2(2*node,start,mid,l,r);
    	else if(l>mid && r<=end) return query2(2*node+1,mid+1,end,l,r);
    	else return min(query2(2*node,start,mid,l,mid),query2(2*node+1,mid+1,end,mid+1,r));
    }

} 


ll update_range2(ll node, ll start, ll end, ll l , ll r, ll val)
{
   if(start==l && end==r)
   {
       lazy2[node] += val;
       tree2[node] += val;
   }
   else
   {
       if(lazy2[node]!=0) push2(node);
       ll mid = (start+end)/2;
       
       if( l>=start && r<=mid ) update_range2(2*node, start, mid, l, r, val);
       else if( l>mid && r<=end ) update_range2(2*node+1, mid+1, end, l, r, val);
       else 
       {  
          update_range2(2*node , start , mid , l , mid , val);
          update_range2(2*node + 1, mid+1 , end, mid+1 , r , val);
       }

       tree2[node] = min(tree2[2*node],tree2[2*node+1]);
   }
    
    return 0;

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

    ll t,l,r,idx,val,n,q;
    char c;
    cin >> t;

    while(t--)
    {
        cin >> n >> q;
        vector<ll> letters(n);
        for(ll i=0,tmp=0 ; i<n ; ++i) 
        	{ 
        		cin >> letters[i];
        		tmp += letters[i];
        		sum[i] = tmp;
        	}
 
       memset(lazy1 , 0 , sizeof(lazy1));
       memset(lazy2 , 0 , sizeof(lazy2));
       build1(1,0,n-1);
       build2(1,0,n-1);

       while(q--)
       {
       		cin >> c;
       		if(c=='U') 
       		{
       			cin >> idx >> val;
       			update_range1(1,0,n-1,idx-1,n-1,val-letters[idx-1]);
            update_range2(1,0,n-1,idx-1,n-1,val-letters[idx-1]);
       			letters[idx-1] = val;
       		}
       		else 
       		{
       			cin >> l >> r;
       			ll q1,q2;
       			q1 = query1(1,0,n-1,r-1,n-1);
       			if(l-2 >= 0)
       			q2 = query2(1,0,n-1,0,l-2);
       		    else q2 = 0;
       		    if(q2>0) q2 = 0;
       		    cout << q1 - q2 << endl;
       		}

       }

    }

    return 0;
} 
