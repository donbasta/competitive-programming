#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    if (n <= 5) {
        cout << "NO" << '\n';
        return;
    }
    if (n % 3 != 0) {
        cout << "YES" << '\n';
        cout << 1 << ' ' << 2 << ' ' << (n - 3) << '\n';
        return;
    }
    if (n % 3 == 0) {
        if (n >= 12) {
            cout << "YES" << '\n';
            cout << 1 << ' ' << 4 << ' ' << (n - 5) << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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