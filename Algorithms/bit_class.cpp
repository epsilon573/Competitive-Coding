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

// Bit class by Rachit Jain
class Bit{
    
    ll x;
    int _bits; 

    #define mask(b) (1LL<<(_bits-b)) 
public:
    
    Bit() {}
    
    Bit(ll &y, int bits=10) { 
        init(y, bits);
    }

    void init(ll &y, int bits=10) {
        x = y;
        _bits = bits-1;
    }
    
    bool get(int &b) {
        return (x & mask(b)) != 0;
    }

    void set(int &b) {
        x |= mask(b);
    }

    void reset(int &b) {
        if(get(b))
            x ^= mask(b);
    }

    void set(int &b,int k) {
        if(k == 1) {
            set(b);
        }
        else {
            reset(b);
        }
    }

    void display() {
        for(int i=0 ; i<_bits ; ++i)
        {
            if((*this).get(i)) cout << '1';
            else cout << '0';
        }
    }    

    ll toInt() {
        return x;
    }

} bitX, bitY;

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

    ll num = 8; int bit_num = 8;
    Bit hello(num);

    hello.set(bit_num,0);
    hello.display();

    return 0;
} 