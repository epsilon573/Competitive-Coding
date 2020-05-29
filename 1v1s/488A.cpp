// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod  = 1e9+7;
const db eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = LLONG_MAX;
const ll minf = LLONG_MIN;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cerr << #x << " " << x << endl

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  
/* A function to check whether point P(x, y) lies inside the triangle formed  
   by A(x1, y1), B(x2, y2) and C(x3, y3) */ 
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{    
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
   float A1 = area (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
   float A2 = area (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
   float A3 = area (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
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

    vector<pair<int,int>> square , tilt;
    int xmin = 1000 , xmax = -1000 , ymin = 1000 , ymax = -1000;

    for(int i=0 ; i<4  ; ++i)
    {
        int x,y;
        cin >> x >> y;

        square.pb(mp(x,y));
        xmax = max(x,xmax);
        xmin = min(x,xmin);
        ymax = max(y,ymax);
        ymin = min(y,ymin);
    }

    for(int i=0 ; i<4  ; ++i)
    {
        int x,y;
        cin >> x >> y;

        tilt.pb(mp(x,y));
    }

    sort(square.begin() , square.end());
    sort( tilt.begin() , tilt.end() );
    
    swap(tilt[2],tilt[3]);

        int x1 = tilt[0].first , y1 = tilt[0].second;
        int x2 = tilt[1].first , y2 = tilt[1].second;
        int x3 = tilt[2].first , y3 = tilt[2].second;
        int x4 = tilt[3].first , y4 = tilt[3].second;
        
       // deb(xmax); deb(xmin); deb(ymax); deb(ymin);
       // deb(x1); deb(x2); deb(y1); deb(y2); deb(x3); deb(y3);
        
        for( int x=x1,y=y1 ; x!=x2 && y!=y2 ; x++ , y--)
        {
            if(x<=xmax && y<=ymax && y>=ymin && x>=xmin)
            {
                cout << "YES"; return 0;
            }
        }

        for( int x=x2,y=y2 ; x!=x3 && y!=y3 ; x++ , y++)
        {
            if(x<=xmax && y<=ymax && y>=ymin && x>=xmin)
            {
                cout << "YES"; return 0;
            }
        }

        for( int x=x3,y=y3 ; x!=x4 && y!=y4 ; x-- , y++)
        {
            if(x<=xmax && y<=ymax && y>=ymin && x>=xmin)
            {
                cout << "YES"; return 0;
            }
        }

        for( int x=x4,y=y4 ; x!=x1 && y!=y1 ; x-- , y--)
        {
            if(x<=xmax && y<=ymax && y>=ymin && x>=xmin)
            {
                cout << "YES"; return 0;
            }
        }
        
        for(auto it : square)
        if(isInside(x1,y1,x2,y2,x4,y4,it.first,it.second) 
            ||
            isInside(x2,y2,x3,y3,x4,y4,it.first,it.second))
        {
            cout << "YES" ; return 0;
        }
           

    cout << "NO";
    return 0;
} 
