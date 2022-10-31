#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 100;
const ll mode = 1e9 + 7;
const double eps = 1e-8;
const string BA[2] = {"Bob", "Alice"};
const string NY[2] = {"No", "Yes"};

int n, m;
string s[maxn];

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> s[i], s[i] = ' ' + s[i] + '0';
    vector up(n + 1, vector<int>(m + 1, 0));
    vector sm(n + 1, vector<int>(m + 1, 0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            sm[i][j] = sm[i][j - 1] + s[i][j] - '0';
            if(s[i][j] == '0') up[i][j] = 0;
            else up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
        }
    }
    ll ans = 0;
    for(int l = 1;l <= n;l++) { //down line
        vector<int> sk;
        for(int j = 1;j <= m;j++) {
            if(s[l][j] == '0') {
                if(!sk.empty()) {
                    int ed = sk.back();
                    while(!sk.empty()) {
                        if(l == n || sm[l + 1][ed] - sm[l + 1][sk.back() - 1] == ed - sk.back() + 1) ans++;
                        sk.pop_back();
                    }
                }
            } else {
                if(!sk.empty() && up[l][sk.back()] > up[l][j]) {
                    int ed = sk.back();
                    while(!sk.empty() && up[l][sk.back()] > up[l][j]) {
                        if(l == n || sm[l + 1][ed] - sm[l + 1][sk.back() - 1] == ed - sk.back() + 1) ans++;
                        sk.pop_back();
                    }
                }
                sk.push_back(j);
            }
        }
        if(!sk.empty()) {
            int ed = sk.back();
            while(!sk.empty()) {
                if(l == n || sm[l + 1][ed] - sm[l + 1][sk.back() - 1] == ed - sk.back() + 1) ans++;
                sk.pop_back();
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    // cin >> T;
    while(T-- > 0) solve();
}