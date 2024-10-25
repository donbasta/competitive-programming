#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<bool> ok(4, true);
    for (int i = 0; i < n; i++) {
        ok[0] = ok[0] & (x[i] >= 0);
        ok[1] = ok[1] & (x[i] <= 0);
        ok[2] = ok[2] & (y[i] >= 0);
        ok[3] = ok[3] & (y[i] <= 0);
    }
    if (ok[0] || ok[1] || ok[2] || ok[3]) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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