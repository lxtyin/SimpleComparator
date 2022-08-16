#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e7 + 100;
const int mode = 998244353;

int pri[maxn], h = 0;
int mip[maxn];

void solve() {
    int n, Q;
    cin >> n >> Q;
    map<ll, ll> ans;
    while(Q-- > 0) {
        int u, v;
        cin >> u >> v;
        if(__gcd(u, v) == 1) {
            cout << "1 1\n";
        } else {
            cout << "2 ";
            set<int> pr;
            ll res = __gcd(u, v) == 2 ? -1 : 0;
            while(u > 1) {
                int p = mip[u];
                while(u % p == 0) u /= p;
                pr.insert(p);
            }
            while(v > 1) {
                int p = mip[v];
                while(v % p == 0) v /= p;
                pr.insert(p);
            }
            ll s = 1;
            vector<int> a;
            for(auto x : pr) a.push_back(x), s *= x;
            if(ans.count(s)) {
                cout << ans[s] << '\n';
            } else {
                int m = a.size();
                assert(m <= 15);
                for(int i = 1;i < (1 << m);i++) {
                    ll cur = 1, cnt = 0;
                    for(int j = 0;j < m;j++) {
                        if(i & (1 << j)) {
                            cnt++;
                            cur *= a[j];
                        }
                    }
                    if(cnt & 1) (res += n / cur) %= mode;
                    else (res -= n / cur) %= mode;
                }
                ans[s] = (n - res + mode) % mode;
                cout << ans[s] << '\n';
            }
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<bool> isp(maxn, true);
    for(int i = 2;i < maxn;i++) {
        if(isp[i]) {
            pri[++h] = i;
            mip[i] = i;
        }
        for(int j = 1;j <= h && pri[j] * i < maxn; j++) {
            isp[pri[j] * i] = false;
            mip[pri[j] * i] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    
    int T = 1;
    // cin >> T;
    while(T--) solve();
}