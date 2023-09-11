#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ve(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            ve[j].push_back(x);
        }
    }
    for (int i = 0; i < m; i++) {
        sort(ve[i].begin(), ve[i].end());
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int fa = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            ans += 1ll * ve[i][j] * fa;
            fa -= 2;
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