#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> routes;
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        routes.emplace_back(u, v);
        deg[u]++, deg[v]++;
    }

    const int INF = 2e9;
    int mn = INF;
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] < mn) {
            idx = i, mn = deg[i];
        }
    }

    vector<int> colors;
    if (mn == n - 1) {  // complete graph
        bool bruh = true;
        cout << 3 << '\n';
        for (auto r : routes) {
            if (r.first == idx || r.second == idx) {
                if (bruh) {
                    colors.push_back(3);
                    bruh = false;
                } else {
                    colors.push_back(2);
                }
            } else {
                colors.push_back(1);
            }
        }
    } else {
        cout << 2 << '\n';
        for (auto r : routes) {
            if (r.first == idx || r.second == idx) {
                colors.push_back(1);
            } else {
                colors.push_back(2);
            }
        }
    }
    for (auto c : colors) {
        cout << c << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}