#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    k = n * (n + 1) / 2 - k;
    if (k == (n * (n + 1) / 2)) {
        for (int i = 0; i < n; i++) {
            cout << -1 << ' ';
        }
        cout << '\n';
        return;
    }
    int t;
    for (int i = 0; i <= n; i++) {
        if (i * (i + 1) / 2 > k) {
            t = i - 1;
            break;
        }
    }
    int r = k - t * (t + 1) / 2;
    vector<int> ans;
    if (r == 0) {
        for (int i = 0; i < t; i++) ans.push_back(-1);
    } else {
        for (int i = 0; i < r - 1; i++) ans.push_back(-1);
        ans.push_back(r - t - 2);
        ans.push_back(t + 1 - r);
        for (int i = 0; i < t - r; i++) ans.push_back(-1);
    }
    ans.push_back(t + 1);
    while (ans.size() < n) ans.push_back(1);
    while (ans.size() > n) ans.pop_back();
    for (auto e : ans) {
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