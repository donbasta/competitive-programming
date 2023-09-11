#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    ll L = 0, R = m / k;
    while (R - L >= 3) {
        ll M1 = L + (R - L) / 3;
        ll M2 = R - (R - L) / 3;
        ll F1 = max(0LL, M1 - ak) + max(0LL, m - M1 * k - a1);
        ll F2 = max(0LL, M2 - ak) + max(0LL, m - M2 * k - a1);
        if (F1 > F2) {
            L = M1 + 1;
        } else {
            R = M2;
        }
    }
    ll ans = 1e18;
    for (ll x = L; x <= R; x++) {
        ans = min(ans, max(0LL, x - ak) + max(0LL, m - x * k - a1));
    }
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