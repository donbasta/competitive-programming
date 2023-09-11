#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    int cur = (1 << 30) - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur &= x;
        if (cur == 0) {
            ans++;
            cur = (1 << 30) - 1;
        }
    }
    if (ans == 0)
        ans = 1;
    else if (cur == 0)
        ans++;
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