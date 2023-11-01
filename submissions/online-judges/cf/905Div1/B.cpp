#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, t;
    cin >> n >> t;
    vector<unordered_map<int, set<int>>> adj(t);
    for (int i = 0; i < t; i++) {
        int mi;
        cin >> mi;
        for (int j = 0; j < mi; j++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[i][u].insert(v);
            adj[i][v].insert(u);
        }
    }

    int k;
    cin >> k;
    vector<int> ts(k);
    for (int i = 0; i < k; i++) {
        cin >> ts[i];
        --ts[i];
    }

    set<int> expand_nodes;
    set<int> rem;
    if (adj[ts[0]].count(0)) {
        expand_nodes.insert(0);
    }
    rem.insert(0);
    for (int i = 0; i < k; i++) {
        set<int> tmp;
        for (auto c : expand_nodes) {
            tmp.insert(c);
            for (auto d : adj[ts[i]][c]) {
                if (rem.count(d)) continue;
                if (d == n - 1) {
                    cout << i + 1 << '\n';
                    return;
                }
                tmp.insert(d);
                adj[ts[i]][d].erase(c);
            }
            adj[ts[i]].erase(c);
        }
        for (auto e : tmp) rem.insert(e);
        expand_nodes.clear();
        if (i < k - 1) {
            for (auto e : tmp) {
                if (adj[ts[i + 1]].count(e)) {
                    expand_nodes.insert(e);
                }
            }
            for (auto e : adj[ts[i + 1]]) {
                if (rem.count(e.first)) {
                    expand_nodes.insert(e.first);
                }
            }
        }
    }
    cout << -1 << '\n';
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