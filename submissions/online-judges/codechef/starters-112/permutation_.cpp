#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, x;
    cin >> n >> x;
    if (x * 2 <= n) {
        for (int i = x; i >= 1; i--) {
            cout << i << ' ';
        }
        for (int i = x + 1; i <= n - x; i++) {
            cout << i << ' ';
        }
        for (int i = n; i >= n - x + 1; i--) {
            cout << i << ' ';
        }
    } else if (x * 2 >= n + 2) {
        for (int i = x; i <= n; i++) {
            cout << i << ' ';
        }
        for (int i = n - x + 2; i <= x - 1; i++) {
            cout << i << ' ';
        }
        for (int i = 1; i <= n - x + 1; i++) {
            cout << i << ' ';
        }
    } else {
        cout << -1;
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
        el_psy_congroo();
    }

    return 0;
}