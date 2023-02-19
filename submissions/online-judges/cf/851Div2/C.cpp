#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    vector<pair<int, int>> ret;
    ret.emplace_back(1, n + (n + 1) / 2);
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            ret.emplace_back(i, 2 * n + 1 - i / 2);
        } else {
            ret.emplace_back(i, n + (n + 1) / 2 - i / 2);
        }
    }
    for (auto e : ret) {
        cout << e.first << ' ' << e.second << '\n';
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