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
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ve.emplace_back(l, b);
    }
    sort(ve.begin(), ve.end());
    vector<pair<int, int>> merged;
    int l = ve[0].first, r = ve[0].second;
    for (int i = 1; i < n; i++) {
        if (ve[i].first > r) {
            merged.emplace_back(l, r);
            l = ve[i].first;
            r = ve[i].second;
        } else {
            r = max(r, ve[i].second);
        }
    }
    merged.emplace_back(l, r);
    int sz = merged.size();
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int idx = lower_bound(merged.begin(), merged.end(), make_pair(x + 1, -1)) - merged.begin();
        if (idx == 0) {
            cout << x << ' ';
        } else {
            idx--;
            if ((merged[idx].first <= x) && (merged[idx].second >= x)) {
                cout << merged[idx].second << ' ';
            } else {
                cout << x << ' ';
            }
        }
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