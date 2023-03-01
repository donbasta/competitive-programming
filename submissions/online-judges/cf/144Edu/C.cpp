#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll mod = 998244353;

void solve() {
    ll l, r;
    cin >> l >> r;
    int sz = 0;
    ll tmp = l;
    while (tmp <= r) {
        sz++;
        tmp *= 2;
    }
    if (sz == 1) {
        cout << 1 << ' ' << r - l + 1 << '\n';
        return;
    }
    ll atas = r / (1 << (sz - 1));
    ll mid = r / (3ll * (1 << (sz - 2)));
    ll ans = 0;
    if (mid < l) {
        ans = atas - l + 1;
    } else if (mid >= l) {
        ans = (atas - mid);
        ans += 1ll * (mid - l + 1) * (sz);
    }
    ans %= mod;
    cout << sz << ' ' << ans << '\n';
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