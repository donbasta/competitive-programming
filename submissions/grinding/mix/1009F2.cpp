#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> mx_idx(n, -1), mx(n, -1);
    const function<vector<int>(int, int)> dfs = [&](int v, int p) -> vector<int> {
        vector<int> de = {1};
        mx[v] = 1;
        mx_idx[v] = 0;
        for (auto c : adj[v]) {
            if (c == p) continue;
            vector<int> T = dfs(c, v);
            if (T.size() >= de.size()) {
                de.swap(T);
                de.push_back(1);
                if (mx[c] > 1) {
                    mx[v] = mx[c];
                    mx_idx[v] = mx_idx[c] + 1;
                }
                for (int i = 0; i < (int)T.size() - 1; i++) {
                    de[de.size() - T.size() + i] += T[i];
                    if (de[de.size() - T.size() + i] >= mx[v]) {
                        mx[v] = de[de.size() - T.size() + i];
                        mx_idx[v] = (int)T.size() - 1 - i;
                    }
                }
            } else {
                for (int i = 0; i < T.size(); i++) {
                    de[de.size() - T.size() - 1 + i] += T[i];
                    if (de[de.size() - T.size() - 1 + i] >= mx[v]) {
                        mx[v] = de[de.size() - T.size() - 1 + i];
                        mx_idx[v] = (int)T.size() - i;
                    }
                }
            }
        }
        return de;
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cout << mx_idx[i] << '\n';
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