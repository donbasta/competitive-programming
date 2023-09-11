#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll tmp = 0;
        ll kur = 0;
        for (int j = 1; j <= i; j++) {
            tmp += 1ll * j * j;
            kur = max(kur, 1ll * j * j);
        }
        for (int j = i + 1; j <= n; j++) {
            tmp += 1ll * j * (n + i + 1 - j);
            kur = max(kur, 1ll * j * (n + i + 1 - j));
        }
        ans = max(ans, tmp - kur);
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