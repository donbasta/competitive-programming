#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

ll a[3], b[3], c[3], d[3];
ll s[N + 5], x[N + 5], y[N + 5];
ll n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }
    cin >> a[0] >> b[0] >> c[0] >> d[0];
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    cin >> a[1] >> b[1] >> c[1] >> d[1];
    for (int i = 1; i <= k; i++) {
        cin >> y[i];
    }
    cin >> a[2] >> b[2] >> c[2] >> d[2];
    for (int i = k + 1; i <= n; i++) {
        s[i] = (a[0] * s[i - 2] + b[0] * s[i - 1] + c[0]) % d[0];
        x[i] = (a[1] * x[i - 2] + b[1] * x[i - 1] + c[1]) % d[1];
        y[i] = (a[2] * y[i - 2] + b[2] * y[i - 1] + c[2]) % d[2];
    }
    ll tot = 0, mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        tot += s[i];
        mn += x[i];
        mx += (x[i] + y[i]);
    }
    if (tot < mn || tot > mx) {
        cout << -1 << '\n';
        return;
    }
    ll move = 0, need = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] > x[i] + y[i]) {
            move += (s[i] - x[i] - y[i]);
        } else if (s[i] < x[i]) {
            need += (x[i] - s[i]);
        }
    }
    ll ans = max(need, move);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}