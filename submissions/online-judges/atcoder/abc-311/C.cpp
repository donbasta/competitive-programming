#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        --ve[i];
    }
    vector<int> ret;
    vector<bool> vis(n);
    int cur = 0;
    while (!vis[cur]) {
        vis[cur] = true;
        cur = ve[cur];
    }
    vis.assign(n, false);
    int tmp = cur;
    while (!vis[tmp]) {
        vis[tmp] = true;
        ret.push_back(tmp);
        tmp = ve[tmp];
    }
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << e + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}