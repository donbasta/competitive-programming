#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
        cout << 1 << '\n';
        return;
    }
    int ans = a + 2 * min(b, c);
    if (b < c) swap(b, c);
    ans += min(a + 1, b - c + d);
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