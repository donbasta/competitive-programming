#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll g1(int px, int qx, int py, int qy) {
    return p1[qx][qy] - p1[qx][py - 1] - p1[px - 1][qy] + p1[px - 1][py - 1];
}

ll g2(int px, int qx, int py, int qy) {
    return p2[qx][qy] - p2[qx][py - 1] - p2[px - 1][qy] + p2[px - 1][py - 1];
}

void solve() {
    cin >> n >> m >> A >> B;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll x;
            cin >> x;
            p1[i][j] = p1[i - 1][j] + p1[i][j - 1] + x - p1[i - 1][j - 1];
            p2[i][j] = p2[i - 1][j] + p2[i][j - 1] + x * x - p2[i - 1][j - 1];
        }
    }
    ll ans = 1e18;
    for (int i = 1; i + A - 1 <= n; i++) {
        for (int j = 1; j + B - 1 <= m; j++) {
            ans = min(ans, query(i, i + A - 1, j, j + B - 1));
        }
    }
    for (int i = 1; i + B - 1 <= n; i++) {
        for (int j = 1; j + A - 1 <= m; j++) {
            ans = min(ans, query(i, i + B - 1, j, j + A - 1));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}