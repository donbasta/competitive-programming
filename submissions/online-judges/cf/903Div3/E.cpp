#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<pair<int, int>> ve;
    vector<int> rb;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (i + ar[i] < n) {
            ve.emplace_back(i, i + ar[i]);
            rb.emplace_back(i + ar[i]);
        }
    }
    if (ve.empty()) {
        cout << n << '\n';
        return;
    }
    sort(ve.begin(), ve.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second < b.second;
    });
    sort(rb.begin(), rb.end());
    int sz = ve.size();
    vector<int> dp(sz), mx(sz);
    dp[0] = ve[0].second - ve[0].first + 1;
    mx[0] = dp[0];
    for (int i = 1; i < sz; i++) {
        int l = ve[i].first, r = ve[i].second;
        int b = lower_bound(rb.begin(), rb.end(), l) - rb.begin();
        --b;
        dp[i] = (b >= 0 ? mx[b] : 0) + (r - l + 1);
        mx[i] = max(mx[i - 1], dp[i]);
    }
    int ans = (n - mx[sz - 1]);
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