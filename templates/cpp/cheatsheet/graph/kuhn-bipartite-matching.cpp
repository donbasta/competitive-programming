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

    void add_edge(int u, int v) { //u in the first part, v in the second part
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
