#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int m;
    cin >> m;
    vector<int> num(m);
    unordered_map<int, int> last;
    for (int i = 0; i < m; i++) {
        cin >> num[i];
        for (int j = 0; j < num[i]; j++) {
            int x;
            cin >> x;
            last[x] = i;
        }
    }
    vector<vector<int>> pos(m);
    for (auto e : last) {
        pos[e.second].push_back(e.first);
    }
    vector<int> ret;
    for (int i = 0; i < m; i++) {
        if (pos[i].empty()) {
            cout << -1 << '\n';
            return;
        } else {
            ret.push_back(pos[i][0]);
        }
    }
    for (auto e : ret) {
        cout << e << ' ';
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