#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> ve(n);
    ve[n - 1] = y;
    for (int i = n - 2; i >= 0; i--) {
        ve[i] = ve[i + 1] - (n - 1 - i);
    }
    if (ve[0] < x) {
        cout << -1 << '\n';
        return;
    }
    cout << x << ' ';
    for (int i = 1; i < n; i++) {
        cout << ve[i] << " \n"[i == n - 1];
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