#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << '\n';
        for (int i = 0; i < n; i++) cout << 0 << '\n';
        return;
    }
    vector<vector<int>> ve(n, vector<int>(m));
    cout << min(m, n + 1) << '\n';
    if (m <= n + 1) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                ve[i][j] = j - i - 1;
            }
            for (int j = i; j >= 0; j--) {
                ve[i][j] = m - 1 - i + j;
            }
        }
        for (int i = m - 1; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                ve[i][j] = j + 1;
            }
            ve[i][m - 1] = 0;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                ve[j][i] = i - 1 - j;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                ve[i][j] = n - i + j;
            }
            for (int j = n + 1; j < m; j++) {
                ve[i][j] = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ve[i][j] << ' ';
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