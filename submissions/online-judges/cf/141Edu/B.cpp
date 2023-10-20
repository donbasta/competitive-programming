#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n * n);
    int sz = n * n;
    int cur = n * n;
    for (int i = 0; i < sz; i += 2) {
        ve[i] = cur--;
    }
    cur = 1;
    for (int i = 1; i < sz; i += 2) {
        ve[i] = cur++;
    }

    vector<vector<int>> ans(n, vector<int>(n));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = ve[idx++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                ans[i][j] = ve[idx++];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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