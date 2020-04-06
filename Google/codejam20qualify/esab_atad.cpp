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

int query(int idx)
{
    int res;

    cout << idx << endl;
    cout.flush();

    cin >> res;
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t,b;
    cin >> t >> b;

    while(t--)
    {
        vector<int> ans(b+1);
        pair<int,int> same = mp(-1,-1) , alter = mp(-1,-1) , nil = mp(-1,-1);
        int l=1,r=b;

        for( int i=1 ; i<=150 ; )
        {
            if( i%10==1 && i!=1 )
            {

                if( same!=nil && alter==nil)
                {
                    int q1 = query(same.first);
                    int q2 = query(same.second);
                    i += 2;
                    if( q1 == ans[same.first] && q2 == ans[same.second] )
                        continue;
                    for( int j=1 ; j<=b ; ++j)
                        ans[j] ^= 1; 
                }

                else if( alter!=nil && same==nil)
                {
                    int q1 = query(alter.first);
                    int q2 = query(alter.second);
                    i += 2;
                    if( q1 == ans[alter.first] && q2 == ans[alter.second] )
                        continue;
                    for( int j=1 ; j<=b ; ++j) ans[j] ^= 1; 
                }

                else
                {
                    int q1 = query(same.first);
                    int q3 = query(alter.first);

                    i += 2;

                    if( q1 == ans[same.first] && q3 == ans[alter.first] )
                    {
                        //cout << "Nothing Changed" << endl;
                        continue;
                    }
                    else if( q1 == ans[same.first] && q3 != ans[alter.first])
                    {
                        //cout << "String was reversed" << endl;
                        reverse( ans.begin() + 1, ans.end() );
                                                
                    }
                    else if( q1 != ans[same.first] && q3 == ans[alter.first] )
                    {
                       //cout << "String was complemented & reversed" << endl;
                       for( int j=1 ; j<=b ; ++j) ans[j] ^= 1; 
                       reverse( ans.begin() + 1, ans.end() );
                    }
                    else
                    {
                        //cout << "String was complemented" << endl;
                        for( int j=1 ; j<=b ; ++j) ans[j] ^= 1;
                    }
                }
            }
            else
            {   
                ans[l] = query(l);
                ans[r] = query(r);
                i += 2;

                if(ans[l] == ans[r] && same == nil)
                {
                    same = mp(l,r);
                }
                else if(ans[l] != ans[r] && alter == nil)
                {
                    alter = mp(l,r);
                }
               
                l++;
                r--;

                if(l>r)
                {
                    for(int j=1 ; j<=b ; ++j) cout << ans[j];
                    cout << endl;
                    cout.flush();
                    string s;
                    cin >> s;
                    if(s == "Y") break;
                    else return 0;  
                }
            }
        }

    }

    return 0;
} 
