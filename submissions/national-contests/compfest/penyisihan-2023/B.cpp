#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> pw_1, pw_2;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        pw_1[a[i]] = b[i];
    }
    cin >> m;
    vector<int> c(m), d(m);
    for (int i = 0; i < m; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> d[i];
    for (int i = 0; i < m; i++) {
        pw_2[c[i]] = d[i];
    }
    int ans = 1;
    const int MOD = 998244353;
    for (auto e : pw_2) {
        if (pw_1.find(e.first) == pw_1.end()) {
            cout << 0 << '\n';
            return;
        }
        if (pw_1[e.first] < e.second) {
            cout << 0 << '\n';
            return;
        }
        if (pw_1[e.first] > e.second) {
            ans = (1ll * ans * 2) % MOD;
        }
    }
    for (auto e : pw_1) {
        if (pw_2.find(e.first) == pw_2.end()) {
            ans = (1ll * ans * 2) % MOD;
        }
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