#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = n + 1;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        ve.emplace_back(a[i], i);
    }
    sort(ve.begin(), ve.end());
    int sum = 0;
    vector<bool> udah(n);
    for (int i = 1; i <= n; i++) {
        sum += ve[i - 1].first;
        udah[ve[i - 1].second] = true;
        if (sum > m) {
            break;
        }
        if (i == n) {
            ans = min(ans, 1);
        } else if (i < n && !udah[i]) {
            ans = min(ans, n - i + 1);
            if (sum + a[i] - ve[i - 1].first <= m) {
                ans = min(ans, n - i);
            }
        } else if (i < n && udah[i]) {
            ans = min(ans, n - i);
        }
    }
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