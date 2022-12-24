#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ar(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }
    int ans = -1;
    for (int sel = 1 - n; sel <= n - 1; sel++) {
        int temp = 0;
        int x, y;
        if (sel > 0) {
            x = sel, y = 0;
        } else {
            x = 0, y = -sel;
        }
        while (x < n && y < n) {
            temp += ar[x][y];
            x++, y++;
        }
        ans = max(ans, temp);
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
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}