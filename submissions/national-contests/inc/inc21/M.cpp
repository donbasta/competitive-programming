#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll k, s, n;
    cin >> k >> s >> n;
    if (k * s > n) {
        cout << "NO" << '\n';
        return;
    }
    if ((k == 2) && (n & 1)) {
        cout << "NO" << '\n';
        return;
    }
    if ((s == 1) && (n & 1) && (n >= 2 * k - 1)) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}