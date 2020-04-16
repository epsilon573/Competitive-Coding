#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;
vector<vector<int>> adj(10001);
vector<bool> vis(10001,false);
vector<ll> lvl(10001),sum(10001);

void dfs(ll node, ll par)
{
    vis[node]=true;
    parent[node] = par ;
    lvl[node] = lvl[par]+1;
    sum[node] = 1;

    for(auto x : adj[node])
    {
        if(!vis[x] && x!=parent[node])
           {    
              dfs(x,node);
              sum[node] += sum[x]; 
           }
    }    
}

int main()
{
    ll t,e,x,y;
    cin >> t;
    
    while(t--)
    {
        ans=0;
        cin >> e;
        
        for(int i=0 ; i<e ; ++i)
        {
            cin >> x >> y;
            tree[x].emplace_back(y);
            tree[y].emplace_back(x);
        }
        
        //cout << ans << endl;
        
        for(int i=1 ; i<=10000 ; ++i)
        {
            if(vis[i]==false)
               dfs(i,tree,vis);
        }

        cout << ans << endl;        
    }
    
    return 0;
}