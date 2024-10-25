#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        for (auto c : adj[i]) {
            deg[i] += (c == '1');
        }
    }
    if (*min_element(deg.begin(), deg.end()) == 0) {
        cout << 1 << '\n';
        cout << (min_element(deg.begin(), deg.end()) - deg.begin() + 1) << '\n';
        return;
    }
    int cc = 0, sz;
    vector<bool> vis(n);
    vector<vector<int>> parts;
    vector<int> tmp, clique_sizes;
    const function<void(int)> dfs = [&](int v) {
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == '0') continue;
            if (vis[i]) continue;
            sz++;
            tmp.push_back(i);
            vis[i] = true;
            dfs(i);
        }
    };
    int can = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        tmp.clear();
        tmp.push_back(i);
        sz = 1;
        dfs(i);
        for (auto v : tmp) {
            if (deg[v] < sz - 1) {
                can = v;
            }
        }
        parts.push_back(tmp);
        clique_sizes.push_back(sz);
    }
    // cerr << parts.size() << '\n';
    // for (auto e : parts) {
    //     for (auto ee : e) {
    //         cerr << ee << ' ';
    //     }
    //     cerr << '\n';
    // }
    if (parts.size() == 1) {
        cout << 0 << '\n';
    } else if (can != -1) {
        cout << 1 << '\n';
        cout << (can + 1) << '\n';
    } else if (clique_sizes.size() == 1) {
        cout << 0 << '\n';
    } else if (clique_sizes.size() == 2) {
        cout << min(clique_sizes[0], clique_sizes[1]) << '\n';
        if (clique_sizes[0] < clique_sizes[1]) {
            for (auto c : parts[0]) {
                cout << (c + 1) << ' ';
            }
        } else {
            for (auto c : parts[1]) {
                cout << (c + 1) << ' ';
            }
        }
        cout << '\n';
    } else {
        cout << 2 << '\n';
        cout << (parts[0][0] + 1) << ' ' << (parts[1][0] + 1) << '\n';
    }
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