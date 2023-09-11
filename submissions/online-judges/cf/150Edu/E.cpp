#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ve(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ve[x].push_back(i);
    }
    int num;
    cin >> num;
    set<pair<int, int>> se;
    se.emplace(0, n - 1);
    int max_len = n;
    for (int i = n; i > 0; i--) {
        if (max_len == 1) break;
        if (ve[i].empty()) {
        } else {
            for (auto e : ve[i]) {
            }
        }
    }
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