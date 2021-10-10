#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= n; ++i)
#define REP(i,j,n) for(int i = j; i <= n; ++i)
#define pb push_back
#define vec vector
typedef long long ll;
#ifdef ACM_LOCAl
const int maxn = 2e3+10;
#else
const int maxn = 1e6+10;
#endif
const int MOD = 998244353;
const int mod = 1e9+7;
ll gcd(ll a,ll b){
    ll res;
    while(b){
        res = a % b;
        a = b;
        b = res;
    }
    return a;
}
ll addMod(ll a, int b){
    if(a < b)return a;
    else return a % b + b;
}
ll qpow(ll a, ll b, const int mo){
    ll res = 1;
    while(b){
        if(b & 1)res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}
ll qpow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll eulPow(ll a, ll b, ll mo){
    ll res = 1;
    while(b){
        if(b & 1)res = addMod(res * a,mo);
        a = addMod(a*a,mo);
        b >>= 1;
    }
    return res;
}
ll slow_mul(ll a,ll b, ll k){
    ll res = 0;
    while(b){
        if(b & 1)res = (res + a) % k;
        a = a * 2 % k;
        b >>= 1;
    }
    return res;
}
ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}
ll ex_gcd(ll a, ll b, ll & x, ll & y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll res = ex_gcd(b,a%b,y,x);
    y -= a/b * x;
    return res;
}
/*** 欧拉降幂
map<int,int> Phi;
int get_phi(int n){
    if(Phi[n])return Phi[n];
    int res = n, cn = n;
    for(int i = 2; i <= n / i; ++i){
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0)n /= i;
        }
    }
    if(n > 1)res -= res / n;
    return Phi[cn] = res;
}
***/
void init(){

}
int n, m , k;
ll a, b, c;
ll x[3], y[3];
ll calc(ll z){
    return a * z * z + b * z + c - y[0];
}
void solve(){
    cin >> a >> b >> c;
    cin >> x[0] >> x[1] >> y[0] >> y[1] >> y[2];
    if(calc(x[0]) > 0  && calc(x[1]) < 0){
        cout << "Yes\n";
    } else if(calc(x[0]) > 0 &&  calc(x[1]) > 0 && calc(2*x[1] - x[0]) < 0 && calc(x[1]) + y[0] <= y[2]){
        cout << "Yes\n";
    } else cout << "No\n";

}
signed main() {
#ifdef ACM_LOCAl
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
#endif
    int _ = 1;
    cin >> _;
//    init();
    while(_ -- > 0)solve();
    return 0;
}
