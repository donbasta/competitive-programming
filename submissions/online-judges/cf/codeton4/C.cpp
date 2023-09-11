#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    set<int> ada;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (ada.count(x)) {
            ans += c;
        } else {
            ada.insert(x);
        }
    }
    vector<int> ve(ada.begin(), ada.end());
    int sz = ve.size();
    ll tmp = INF;
    for (int i = 0; i < sz; i++) {
        tmp = min(tmp, 1ll * d * (ve[i] - i - 1) + 1ll * c * (sz - i - 1));
    }
    tmp = min(tmp, 1ll * c * sz + 1ll * d);
    ans += tmp;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}