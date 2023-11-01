#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    int cur = 0;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<string> names(n + 1);
    map<string, int> id;

    for (int i = 0; i < n; i++) {
        string a, b, opr;
        cin >> a >> opr >> b;
        if (!id.count(a)) {
            names[cur] = a;
            id[a] = cur++;
        }
        if (!id.count(b)) {
            names[cur] = b;
            id[b] = cur++;
        }
        int ab = 0, ba = 0;
        if (opr == "->") {
            ab = 1, ba = -1;
        }
        adj[id[a]].emplace_back(id[b], ab);
        adj[id[b]].emplace_back(id[a], ba);
    }

    int T = 0;
    vector<int> tin(n + 1), tout(n + 1), depth(n + 1);
    vector<bool> cant(n + 1);
    vector<int> must;
    const function<void(int, int, bool)> dfs = [&](int v, int p, bool f) {
        tin[v] = T++;
        if (f) {
            cant[v] = true;
        }
        for (auto c : adj[v]) {
            bool flag = f;
            if (c.first == p) continue;
            if (c.second == -1) {
                must.push_back(c.first);
            } else if (c.second == 1) {
                flag = 1;
            }
            depth[c.first] = depth[v] + 1;
            dfs(c.first, v, flag);
        }
        tout[v] = T++;
    };
    dfs(0, 0, 0);
    auto is_ancestor = [&](int x, int y) {
        return tin[x] <= tin[y] && tout[x] >= tout[y];
    };

    if (must.empty()) must.push_back(0);
    sort(must.begin(), must.end(), [&](int a, int b) -> bool {
        return depth[a] < depth[b];
    });
    int sz = must.size();
    for (int i = 1; i < sz; i++) {
        assert(is_ancestor(must[i - 1], must[i]));
    }

    vector<string> ret;
    int par = must.back();
    for (int i = 0; i <= n; i++) {
        if (is_ancestor(par, i) && !cant[i]) {
            ret.push_back(names[i]);
        }
    }

    sort(ret.begin(), ret.end());
    for (auto e : ret) {
        cout << e << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}