#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    if (n == 4 && k == 3) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int, int>> ve;
    if (k == n - 1) {
        ve.emplace_back(n - 1, n - 2);
        ve.emplace_back(1, 3);
        ve.emplace_back(0, n - 4);
        for (int i = 0; i < n / 2; i++) {
            if (i == 0 || i == 1 || i == 3) continue;
            ve.emplace_back(i, n - 1 - i);
        }
    } else {
        for (int i = 0; i < n / 2; i++) {
            if (i == 0) {
                ve.emplace_back(k, n - 1);
            } else if (i == k) {
                ve.emplace_back(0, n - 1 - i);
            } else if (n - 1 - i == k) {
                ve.emplace_back(i, 0);
            } else {
                ve.emplace_back(i, n - 1 - i);
            }
        }
    }
    for (auto e : ve) {
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
        el_psy_congroo();
    }

    return 0;
}