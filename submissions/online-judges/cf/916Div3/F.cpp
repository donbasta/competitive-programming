#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> chd(n);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        --x;
        chd[x].push_back(i + 1);
    }

    vector<int> sz(n), dp(n);
    const function<void(int)> dfs_sz = [&](int v) {
        sz[v] = 1;
        for (auto c : chd[v]) {
            dfs_sz(c);
            sz[v] += sz[c];
        }
    };
    dfs_sz(0);

    const function<void(int)> dfs = [&](int v) {
        if (chd[v].empty()) return;
        vector<int> tmp;
        for (auto c : chd[v]) {
            tmp.push_back(sz[c]);
        }
        int idx = max_element(tmp.begin(), tmp.end()) - tmp.begin();
        int mx = tmp[idx];
        if (mx > sz[v] - 1 - mx) {
            int c = chd[v][idx];
            dfs(c);
            int oth = sz[v] - 1 - sz[c];
            dp[v] = dp[c] + min(oth, (oth + sz[c] - 2 * dp[c]) / 2);
        } else {
            dp[v] = (sz[v] - 1) / 2;
        }
    };
    dfs(0);

    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}