#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll n, x;
    cin >> n;
    vector<ll> p(n + 1), d(n);
    cin >> p[0] >> x;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + d[i - 1];
    }
    ll kur = p[0] - p[n];
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        if (p[i] < x) continue;
        ll lol = (p[i] - x) / kur;
        ans = min(ans, p[i] - lol * kur);
    }
    if (ans == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}