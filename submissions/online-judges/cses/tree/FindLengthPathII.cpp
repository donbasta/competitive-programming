#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    const function<int(const deque<int>&, int)> get_prefix = [&](const deque<int>& a, int mx) -> int {
        if (mx < 0) return 0;
        if (mx + 1 >= (int)a.size()) return a[0];
        return a[0] - a[mx + 1];
    };

    ll ans = 0;
    const function<void(deque<int>&, deque<int>&)> comb = [&](deque<int>& a, deque<int>& b) {
        if ((int)a.size() < (int)b.size()) swap(a, b);
        for (int i = 0; i < (int)b.size() - 1; i++) {
            b[i] -= b[i + 1];
        }
        for (int i = 0; i < (int)b.size(); i++) {
            ans += 1ll * b[i] * (get_prefix(a, k2 - i) - get_prefix(a, k1 - 1 - i));
        }
        for (int i = (int)b.size() - 2; i >= 0; i--) b[i] += b[i + 1];
        for (int i = 0; i < (int)b.size(); i++) a[i] += b[i];
    };

    const function<deque<int>(int, int)> dfs = [&](int v, int p) -> deque<int> {
        deque<int> res{1};
        for (auto c : adj[v]) {
            if (c == p) continue;
            deque<int> a = dfs(c, v);
            a.push_front(a.front());
            comb(res, a);
        }
        return res;
    };

    dfs(0, 0);
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