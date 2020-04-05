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

    ll t;
    cin >> t;

    while(t--)
    {

    	ll n; char c; queue<ll> q; 
        cin >> n;
        vector<bool> vis(n),isolate(n);
        vector<ll> lvl(n);

        for(ll i=0 ; i<n ; ++i)
        {
        	cin >> c;
        	if(c=='1')
        	{ 
        		q.push(i);
        		vis[i] = true;
        		lvl[i] = 1;
        	}
        }
        

        ll d;
        cin >> d;
        vector<ll> iso(d);
      
        for(ll i=0 ; i<d ; ++i)
        {
            cin >> iso[i];
        } 

        while(1)
        {
            
            if(q.empty()) break;
            ll z = q.front();
            q.pop();

            if(lvl[z] > d) break;
            if(!isolate[ iso[lvl[z]-1]-1 ])
            {
            	isolate[ iso[lvl[z]-1]-1 ] = true;
                //cout << "Isolated " << iso[lvl[z]-1] << endl;
            }
            if( isolate[z] )
            {
            	if(z+1<n)
                if(!vis[z+1] && !isolate[z+1] ) 
                {
                	q.push(z+1);
                	vis[z+1] = true;
                    //cout << z+1 << " infected " << z+2 << endl;
                	lvl[z+1] = lvl[z] + 1;
                }
            }
            else
            {
             
               if(z-1>=0) 
               if(!vis[z-1])
               {
               	    q.push(z-1);
                	vis[z-1] = true;
                	//cout << z+1 << " infected " << z << endl;
                	lvl[z-1] = lvl[z] + 1;
               }
               
               if(z+1<n) 
               if(!vis[z+1] && !isolate[z+1] ) 
                {
                	q.push(z+1);
                	vis[z+1] = true;
                	//cout << z+1 << " infected " << z+2 << endl;
                	lvl[z+1] = lvl[z] + 1;
                }	
            }
        }
         
        cout << count(vis.begin(),vis.end(),true) << endl;

    }

    return 0;
} 