#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll n, m;
    cin >> n >> m;
    ll ans = INF;

    ll x0 = -1;
    ll l = 0, r = INF;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mid + (mid / m) >= n) {
            x0 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ans = min(ans, x0 * a);

    --x0;
    ll y = max(0LL, n - (x0 + (x0 / m)));
    ans = min(ans, x0 * a + b * y);

    l = 0, r = INF;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mid + (mid / m) >= n - 1) {
            x0 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    y = max(0LL, n - (x0 + (x0 / m)));
    ans = min(ans, x0 * a + b * y);

    ans = min(ans, n * b);

    x0 = 1;
    y = max(0LL, n - (x0 + (x0 / m)));
    ans = min(ans, x0 * a + y * b);

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