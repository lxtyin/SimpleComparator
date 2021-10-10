#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mode = 1e9+7;
const ll maxn = 500010;

ll a, b, c;
ll x0, x1, ya, yb, yc;
ll f(ll x){
    return a * x * x + b * x + c;
}

void solve(){
    cin >> a >> b >> c;
    cin >> x0 >> x1 >> ya >> yb >> yc;
    if(f(x0) > 0 && f(2*x1-x0) < 0 && f(x1) != ya){
        if(f(x1) <= yc){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

signed main(){
#ifdef ACM_LOCAL
    freopen("x.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
