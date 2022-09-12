#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> is_leaf(n, true);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        if (i != p[i]) {
            is_leaf[p[i]] = false;
        }
    }
    vector<vector<int>> paths;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (!is_leaf[i]) continue;
        vector<int> path;
        int j = i;
        while (!vis[j]) {
            path.emplace_back(j + 1);
            vis[j] = true;
            j = p[j];
        }
        paths.emplace_back(path);
    }
    cout << paths.size() << '\n';
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i].size() << '\n';
        for (int j = paths[i].size() - 1; j >= 0; --j) {
            cout << paths[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}