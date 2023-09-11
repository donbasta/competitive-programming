#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    --a, --b;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    const ll INF = 1e18;
    ll ans = INF;
    if ((a < k) && (b < k)) {
        ans = 0;
    } else if ((a < k) && (b >= k)) {
        for (int i = 0; i < k; i++) {
            ans = min(ans, abs(x[i] - x[b]) + abs(y[i] - y[b]));
        }
    } else if ((a >= k) && (b < k)) {
        for (int i = 0; i < k; i++) {
            ans = min(ans, abs(x[i] - x[a]) + abs(y[i] - y[a]));
        }
    } else {
        ans = min(ans, abs(x[a] - x[b]) + abs(y[a] - y[b]));
        ll A = INF, B = INF;
        for (int i = 0; i < k; i++) {
            A = min(A, abs(x[i] - x[a]) + abs(y[i] - y[a]));
        }
        for (int i = 0; i < k; i++) {
            B = min(B, abs(x[i] - x[b]) + abs(y[i] - y[b]));
        }
        ans = min(ans, A + B);
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