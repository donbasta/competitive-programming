#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == n && b == n) {
        cout << "Yes" << '\n';
    } else if (a + b >= n - 1) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
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