#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> p(n), a(m), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[--p[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 1; i < m; i++) {
        if ((pos[a[i]] <= pos[a[i - 1]]) || (pos[a[i]] > pos[a[i - 1]] + d)) {
            cout << 0 << '\n';
            return;
        }
    }
    const int INF = 2e9;
    int lol = INF;
    for (int i = 1; i < m; i++) {
        lol = min(lol, pos[a[i]] - pos[a[i - 1]]);
    }
    if (d + m - 1 >= n) {
        cout << lol << '\n';
        return;
    }
    int bruh = -1;
    for (int i = 1; i < m; i++) {
        bruh = max(bruh, pos[a[i]] - pos[a[i - 1]]);
    }
    assert(bruh <= d);
    int ans = min(d - bruh + 1, lol);
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