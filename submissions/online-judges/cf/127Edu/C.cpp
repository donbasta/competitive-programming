#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> ve(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
        pre[i] = (i ? pre[i - 1] : 0) + ve[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x < pre[i - 1]) {
            break;
        }
        ll R = (x - pre[i - 1]) / i;
        ll L;
        if (i == n || x < pre[i]) {
            L = 0;
        } else {
            L = ((x - pre[i]) / (i + 1)) + 1;
        }
        // cerr << i << ' ' << L << ' ' << R << '\n';
        ans += 1ll * i * (R - L + 1);
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