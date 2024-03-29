#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll x, y;
    cin >> x >> y;
    int n = 2 * (x - y);
    cout << n << '\n';
    for (int i = x; i >= y; i--) {
        cout << i << ' ';
    }
    for (int i = y + 1; i < x; i++) {
        cout << i << ' ';
    }
    cout << '\n';
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