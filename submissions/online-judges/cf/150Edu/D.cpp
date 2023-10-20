#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ve.emplace_back(l, r);
    }
    sort(ve.begin(), ve.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second < b.second;
    });
    int pair = 0;
    int r = ve[0].second;
    int mn_left = 0;
    bool empty = false;
    for (int i = 1; i < n; i++) {
        if (ve[i].first < mn_left) continue;
        if (empty) {
            r = ve[i].second;
            empty = false;
        } else if (ve[i].first <= r) {
            pair++;
            mn_left = ve[i].second + 1;
            empty = true;
        } else {
            r = ve[i].second;
        }
    }
    int ans = n - 2 * pair;
    cout << ans << '\n';
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