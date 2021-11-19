#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> col(n + 1);
    const auto dfs = [&](const auto& self, int v, int p, int lol) -> void {
        col[v] = lol;
        for (auto c : adj[v]) {
            if (c == p) continue;
            self(self, c, v, 1 - lol);
        }
    };
    dfs(dfs, 1, 1, 1);
    vector<int> cnt(2);
    vector<vector<int>> ve(2);
    for (int i = 1; i <= n; i++) {
        cnt[col[i]]++;
        ve[col[i]].emplace_back(i);
    }
    if (cnt[0] > cnt[1]) {
        swap(cnt[0], cnt[1]);
        ve[0].swap(ve[1]);
    }
    vector<int> ans(n + 1);
    vector<int> A, B;
    int R;
    for (int i = 0; i < 20; i++) {
        if ((1 << i) > n) {
            R = (i - 1);
            break;
        }
        if (cnt[0] & (1 << i)) {
            A.emplace_back(i);
        } else {
            B.emplace_back(i);
        }
    }
    int j = 0;
    for (auto sz : A) {
        for (int i = (1 << sz); i < (1 << (sz + 1)); i++) {
            ans[ve[0][j]] = i;
            j++;
        }
    }
    j = 0;
    for (auto sz : B) {
        if ((1 << (sz + 1)) > n) {
            break;
        }
        for (int i = (1 << sz); i < (1 << (sz + 1)); i++) {
            ans[ve[1][j++]] = i;
        }
    }
    for (int i = (1 << R); i <= n; i++) {
        ans[ve[1][j++]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}