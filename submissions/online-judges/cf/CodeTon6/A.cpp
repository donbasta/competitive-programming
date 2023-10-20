#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    ll ans = 0;
    if (n < k) {
        cout << -1 << '\n';
        return;
    }
    if (x < k - 1) {
        cout << -1 << '\n';
        return;
    }
    if (x == k) x = k - 1;
    ans = (k - 1) * k / 2;
    ll need = n - k;
    if (x == k - 1) {
        ans += need * (k - 1);
    } else if (x > k) {
        ans += need * x;
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