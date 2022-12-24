#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html#improved-implementation

struct Kuhn {
    int m1, m2;
    vector<bool> used;
    vector<int> mt;
    vector<vector<int>> adj;

    Kuhn(int m1, int m2) : m1(m1), m2(m2) {
        used.resize(m1);
        mt.assign(m2, -1);
        adj.resize(m1);
    }

    void add_edge(int u, int v) {  // u in the first part, v in the second part
        adj[u].emplace_back(v);
    }

    bool find_augmented_path(int v) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (int to : adj[v]) {
            if (mt[to] == -1 || find_augmented_path(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }

    void go() {
        vector<bool> used1(m1, false);
        for (int v = 0; v < m1; v++) {
            for (int to : adj[v]) {
                if (mt[to] == -1) {
                    mt[to] = v;
                    used1[v] = true;
                    break;
                }
            }
        }

        for (int v = 0; v < m1; v++) {
            if (used1[v]) {
                continue;
            }
            used.assign(m1, false);
            find_augmented_path(v);
        }

        int mx = 0;
        for (int i = 0; i < m2; i++) {
            if (mt[i] != -1) {
                mx++;
                cout << "Matched " << mt[i] + 1 << " and " << i + 1 << '\n';
            }
        }

        cout << "The size of max matching is " << mx << '\n';
    }
};

void solve() {
    Kuhn K = Kuhn(4, 5);
    K.add_edge(0, 0);
    K.add_edge(1, 0);
    K.add_edge(2, 0);
    K.add_edge(2, 2);
    K.add_edge(2, 3);
    K.add_edge(3, 1);
    K.add_edge(3, 4);
    K.go();
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