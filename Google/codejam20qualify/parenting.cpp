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

struct event
{
    ll type; // 0-end , 1-start 
    ll time;
    ll id;

    event(ll _type,ll _time, ll  _id) : type(_type),time(_time),id(_id) {}
};

bool event_cmp(const event& a, const event& b )
{
    if(a.time == b.time) return (a.type < b.type);
    else  return (a.time < b.time);
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

    ll t;
    cin >> t;

    for(ll x=1 ; x<=t ; ++x)
    {
        cout << "Case #"<< x << ": " ;
        ll n;
        cin >> n;
        vector<event> ve;

        for(ll i=0 ; i<n ; ++i)
        {
            ll a,b;
            cin >> a >> b;

            ve.pb( event(1 , a , i) );
            ve.pb( event(0 , b , i) );

        }

        sort(ve.begin(),ve.end(),event_cmp);

        string s(n,'x');
        bool cam = false, jam = false , flag = false; 
        
        for(auto it = ve.begin() ; it!=ve.end() ; ++it)
        {
            if(it->type == 1)
            {
                if(cam && jam)
                {
                    flag = true;
                    break;
                }
                else if(cam == false)
                {
                    s[it->id] = 'C';
                    cam = true;
                }
                else
                {
                    s[it->id] = 'J';
                    jam = true;
                }
            }
            else
            {
                if(s[it->id] == 'C')
                    cam = false;
                else 
                    jam = false;
            }
        }  
        if(flag) cout << "IMPOSSIBLE";
        else cout << s;
        cout << endl;
    }

    return 0;
} 