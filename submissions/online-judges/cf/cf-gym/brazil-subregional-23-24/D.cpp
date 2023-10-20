#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        cost[u][v] = cost[v][u] = l;
        edges.emplace_back(u, v);
    }
    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    vector<vector<int>> st(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) st[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (k == 0) {
                    if (k != i && k != j)
                        st[i][j] = min(st[i][j], cost[i][k] + cost[k][j]);
                } else {
                    if (k != i && k != j) {
                        st[i][j] = min(st[i][j], st[i][k] + st[k][j]);
                        st[i][j] = min(st[i][j], st[i][k] + cost[k][j]);
                        st[i][j] = min(st[i][j], cost[i][k] + st[k][j]);
                        st[i][j] = min(st[i][j], cost[i][k] + cost[k][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cerr << st[i][j] << ' ';
            }
            cerr << '\n';
        }
        cerr << "---\n";
    }
    for (auto e : edges) {
        int i = e.first, j = e.second;
        cout << st[i][j] << '\n';
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