#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int b, c, h;
    cin >> b >> c >> h;
    c += h;
    if (c + 1 <= b) {
        cout << (2 * c + 1) << '\n';
    } else {
        cout << (2 * b - 1) << '\n';
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