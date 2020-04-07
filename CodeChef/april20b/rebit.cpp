#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const ll mod = 998244353;
const db eps = 1e-9;

#define mp make_pair
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << " " << x << endl

ll bin_power_mod(ll base, ll power, ll m) 
{
    base %= m;
    ll res = 1;
    while (power > 0) {
        if (power & 1)
            res = res * base % m;
        base = base * base % m;
        power >>= 1;
    }
    return res;
}

ll frac_mod( ll a, ll b)
{
    return ((a%mod)*bin_power_mod( b , mod-2 , mod))%mod;
}

struct prob
{
    ll p0,p1,pa,pA;

    prob(ll _p0, ll _p1 , ll _pa , ll _pA) : p0(_p0), p1(_p1), pa(_pa), pA(_pA) {}
};

prob operate(prob val1, prob val2 , char oprtr)
{
    prob res = prob(1,1,1,1);

        ll tmp00 = (val1.p0*val2.p0)%mod;
        ll tmp01 = (val1.p0*val2.p1)%mod; 
        ll tmp0a = (val1.p0*val2.pa)%mod;
        ll tmp0A = (val1.p0*val2.pA)%mod;
        ll tmp10 = (val1.p1*val2.p0)%mod;
        ll tmpa0 = (val1.pa*val2.p0)%mod;
        ll tmpA0 = (val1.pA*val2.p0)%mod;
        ll tmpaA = (val1.pa*val2.pA)%mod;
        ll tmpAa = (val1.pA*val2.pa)%mod; 
        ll tmp11 = (val1.p1*val2.p1)%mod;
        ll tmp1a = (val1.p1*val2.pa)%mod;
        ll tmpa1 = (val1.pa*val2.p1)%mod;
        ll tmpaa = (val1.pa*val2.pa)%mod;
        ll tmp1A = (val1.p1*val2.pA)%mod;
        ll tmpA1 = (val1.pA*val2.p1)%mod;
        ll tmpAA = (val1.pA*val2.pA)%mod;    

    if(oprtr == '&')
    {
        res.p0 = tmp00+tmp01+tmp0a+tmp0A+tmp10+tmpa0+tmpA0+tmpaA+tmpAa;
        res.p0 %= mod;
        res.p1 = tmp11;
        res.pa = tmp1a+tmpa1+tmpaa; res.pa %= mod;
        res.pA = tmp1A+tmpA1+tmpAA; res.pA %= mod;

    } 
    else if(oprtr == '|')
    {
        res.p0 = tmp00;
        res.p1 = tmp11 + tmp10 + tmp1a + tmpa1  + tmp01 + tmpaA +tmpAa + tmp1A + tmpA1; 
        res.p1 %= mod;
        res.pa = tmpaa + tmp0a + tmpa0 ; res.pa %= mod;
        res.pA = tmpAA + tmp0A + tmpA0; res.pA %= mod;
    }
    else if(oprtr == '^')
    {
        res.p0 = tmp00 + tmp11 + tmpaa + tmpAA ; res.p0 %= mod;
        res.p1 = tmp10 + tmp01 + tmpaA + tmpAa ; res.p1 %= mod;
        res.pa = tmp1A + tmpA1 + tmp0a + tmpa0 ; res.pa %= mod;
        res.pA = tmp1a + tmpa1 + tmp0A + tmpA0 ; res.pA %= mod;
        
    } 

    return res;            
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

    while(t--)
    {
        stack<prob> values;
        stack<char> ops;
        string s;
        cin >> s;
        
        prob def = prob(frac_mod(1,4),frac_mod(1,4),frac_mod(1,4),frac_mod(1,4));  

        for(ll i=0 ; i<s.size() ; ++i)
        {
            if(s[i]=='#') values.push(def);
            else if(s[i]!=')') ops.push(s[i]);
            else
            {
                prob val1 = values.top();
                values.pop();
                prob val2 = values.top();
                values.pop();
                char opr = ops.top();
                ops.pop();
                ops.pop();
                values.push( operate(val1, val2, opr) );
            }
        }

        prob end_result = values.top();
        values.pop();
        cout << end_result.p0 << " "; 
        cout << end_result.p1 << " ";
        cout << end_result.pa << " ";
        cout << end_result.pA << endl;
    }
    
    return 0;
} 