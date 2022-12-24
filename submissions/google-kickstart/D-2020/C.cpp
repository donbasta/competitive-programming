#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, a, b;
vector<vector<int>> adj1, adj2, adj;
vector<int> dep, cnt1, cnt2, cur;

void answer(ld ans, int tc) {
    cout << "Case #" << tc << ": ";
    cout << fixed << setprecision(10) << ans << '\n';
}

void dfs(int v, int par, int d) {
    dep[v] = d;
    for (auto i : adj[v]) {
        if (i == par)
            continue;
        dfs(i, v, d + 1);
    }
}

void dfs1(int v, int par, int d) {
    cur[d] = v;
    if (d >= a) {
        adj1[cur[d - a]].push_back(v);
        adj1[v].push_back(cur[d - a]);
    }
    for (auto i : adj[v]) {
        if (i == par)
            continue;
        dfs1(i, v, d + 1);
    }
}

void dfs2(int v, int par, int d) {
    cur[d] = v;
    if (d >= b) {
        adj2[cur[d - b]].push_back(v);
        adj2[v].push_back(cur[d - b]);
    }
    for (auto i : adj[v]) {
        if (i == par)
            continue;
        dfs2(i, v, d + 1);
    }
}

void dfsCntChild1(int v, int par) {
    cnt1[v] = 1;
    for (auto i : adj1[v]) {
        if (i == par)
            continue;
        dfsCntChild1(i, v);
        cnt1[v] += cnt1[i];
    }
}

void dfsCntChild2(int v, int par) {
    cnt2[v] = 1;
    for (auto i : adj2[v]) {
        if (i == par)
            continue;
        dfsCntChild2(i, v);
        cnt2[v] += cnt2[i];
    }
}

ld calc(int v) {
    ld ret = 0.0;
    ld xx = (ld)(cnt1[v]) / (ld)(n);
    ld yy = (ld)(cnt2[v]) / (ld)(n);
    ret = xx + yy - (xx * yy);
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> a >> b;

        adj1.resize(n + 1);
        adj2.resize(n + 1);
        adj.resize(n + 1);
        dep.resize(n + 1);
        cnt1.resize(n + 1);
        cnt2.resize(n + 1);
        cur.resize(n + 1);

        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            adj[x].push_back(i + 1);
            adj[i + 1].push_back(x);
        }
        dfs(1, 0, 0);
        dfs1(1, 0, 0);
        dfs2(1, 0, 0);
        ld ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dep[i] < a)
                dfsCntChild1(i, 0);
            if (dep[i] < b)
                dfsCntChild2(i, 0);
        }

        for (int i = 1; i <= n; i++) {
            ld ex = calc(i);
            ans += ex;
        }
        answer(ans, tc);

        // clean up
        adj1.clear();
        adj2.clear();
        adj.clear();
        dep.clear();
        cnt1.clear();
        cnt2.clear();
        cur.clear();
    }
    return 0;
}