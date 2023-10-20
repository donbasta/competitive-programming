#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<vector<int>> cuts;
    vector<int> cur_idx(n), cur(n);
    const function<void(vector<int>)> cut_poly = [&](vector<int> indices) {
        for (auto e : indices) {
            cerr << e << ' ';
        }
        cerr << '\n';
        int sz = indices.size();
        for (int i = 0; i < sz; i++) {
            cur_idx[indices[i]] = i;
        }
        int ptr = 0;
        int tmp = 0;
        while (tmp < sz && adj[indices[ptr]].empty()) {
            ptr = (ptr + 1) % sz, tmp++;
        }
        if (tmp == sz) {
            cuts.emplace_back(indices);
            return;
        }
        int to = *adj[indices[ptr]].rbegin();
        adj[indices[ptr]].erase(to);
        adj[to].erase(indices[ptr]);
        int st = cur_idx[to];
        vector<int> T1, T2;
        for (int j = st;; j = (j + 1) % sz) {
            T1.push_back(indices[j]);
            if (j == ptr) break;
        }
        for (int j = ptr;; j = (j + 1) % sz) {
            T2.push_back(indices[j]);
            if (j == st) break;
        }
        cut_poly(T1);
        cut_poly(T2);
    };
    iota(cur.begin(), cur.end(), 0);
    cut_poly(cur);

    cerr << cuts.size() << '\n';
    for (auto e : cuts) {
        for (auto v : e) {
            cerr << v << ' ';
        }
        cerr << '\n';
    }
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