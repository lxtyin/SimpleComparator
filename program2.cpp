#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 998244353;
const int P = 998244353;
const int maxn = 1e7 + 10;
const int N = 1002;
const double eps = 1e-8;
const double inf = 1e18;

ll qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a, ll b) {
    ll res;
    while(b) {
        res = a % b;
        a = b;
        b = res;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
void add(int &x, int val) {
    x += val;
    if(x >= mod) x -= mod;
}
void sub(int &x, int val) {
    x -= val;
    if(x < 0) x += mod;
}

bool st[maxn];
ll idx, pr[maxn], mn[maxn];

void get() {
    for(int i = 2; i < maxn; ++i) {
        if(!st[i]) pr[++idx] = i, mn[i] = i;
        for(int j = 1; pr[j] * i < maxn; ++j) {
            st[i * pr[j]] = 1;
            mn[i * pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
bool used[maxn];
ll all[50], tot;
ll n, q;
map<ll, ll> mp;
ll calc() {
    ll ans = 0;
    for (int i = 1; i < (1 << tot); i++){   // 二进制枚举质因子所有组合
        ll tmp = 1, t = 0;
        for(int j = 0; j < tot; j++){   
            if((1ll<<j)&i){       // 如果第 j 位为一
                tmp *= all[j + 1];
                t++;
            } 
        }
        ans += (t & 1 ? n / tmp : -n / tmp);        // 奇加偶减
    }
    return n - ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int tt = 1;      
//    cin >> tt;  
    get();
    while(tt -- > 0) {
        cin >> n >> q;
        
        for(int i = 1; i <= q; ++i) {
            ll u, v;
            cin >> u >> v;
            ll g = gcd(u, v);
            if(g == 1) cout << 1 << " " << 1 << '\n';
            else {
                ll ans = 0;
                if(g == 2) ++ ans;
                ll x = 1;
                tot = 0;
                while(u > 1) {
                    ll cur = mn[u];
                    while(u % cur == 0) u /= cur;
                    all[++tot] = cur;
                    used[cur] = true;
                    x *= cur;
                }
                while(v > 1) {
                    ll cur = mn[v];
                    while(v % cur == 0) v /= cur;
                    if(!used[cur]) {
                        used[cur] = true;
                        x *= cur;
                        all[++tot] = cur;
                    }
                }
                if(!mp.count(x)) {
                    ans += calc();
                    mp[x] = ans;
                }
                
                for(int j = 1; j <= tot; ++j) used[all[j]] = false;
                assert(mp[x] < mod && mp[x] >= 2);
                cout << 2 << " " << mp[x] << '\n';
            }
        }
    }

    return 0;
}