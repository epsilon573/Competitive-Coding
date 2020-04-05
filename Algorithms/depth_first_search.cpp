#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;

void dfs(int idx, vector<vector<int>> &tree,vector<bool> &vis)
{
    vis[idx]=true;
    if(tree[idx].size()) ++ans;
    for(int i=0 ; i<tree[idx].size() ; ++i)
    {
        if(vis[tree[idx][i]]==false)
           {    
              dfs(tree[idx][i],tree,vis); 
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
        vector<vector<int>> tree(10001);
        vector<bool> vis(10001,false);
        
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