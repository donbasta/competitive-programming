#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> s(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    s[0] = 1;
    ll tot = m + (s[1] > 1);
    vector<ll> dif(m + 1);
    for (int i = 0; i < m; i++) {
        dif[i] = (max(0ll, s[i + 1] - s[i] - 1)) / d;
        tot += dif[i];
    }
    dif[m] = (n - s[m]) / d;
    tot += dif[m];
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) {
        ll tmp = tot - (1 + dif[i - 1] + dif[i]);
        if (s[0] == s[1] && i == 1) {
            tmp++;
        }
        ll end = (i == m) ? (n + 1) : s[i + 1];
        tmp += (end - s[i - 1] - 1) / d;
        ans = min(ans, tmp);
    }
    int ret = 0;
    for (int i = 1; i <= m; i++) {
        ll tmp = tot - (1 + dif[i - 1] + dif[i]);
        if (s[0] == s[1] && i == 1) {
            tmp++;
        }
        ll end = (i == m) ? (n + 1) : s[i + 1];
        tmp += (end - s[i - 1] - 1) / d;
        if (tmp == ans) ret++;
    }
    cout << ans << ' ' << ret << '\n';
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