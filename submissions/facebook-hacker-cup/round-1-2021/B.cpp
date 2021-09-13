#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m, a, b;

void solve() {
    cin >> n >> m >> a >> b;
    if (min(a, b) < n + m - 1) {
        cout << "Impossible" << '\n';
        return;
    }
    vector<vector<int>> ve(n, vector<int>(m, 1));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            ve[i][j] = 1000;
        }
    }
    ve[0][0] = a - (n + m - 2);
    ve[0][m - 1] = b - (n + m - 2);
    cout << "Possible" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ve[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}