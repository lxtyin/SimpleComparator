#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    srand(n * time(0));
    double ans = sqrt(n) * sqrt(n);
    ans = sqrt(ans) * sqrt(ans);
    ans = sqrt(ans) * sqrt(ans);
    ans = sqrt(ans) * sqrt(ans);
    cout << setprecision(10) << fixed << ans + 0.5 * rand() / INT_MAX << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("x.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
