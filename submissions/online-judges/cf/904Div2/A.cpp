#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

bool ok(int a, int b) {
    int ret = 0;
    while (a) {
        ret += (a % 10);
        a /= 10;
    }
    return (ret % b == 0);
}

void el_psy_congroo() {
    int x, k;
    cin >> x >> k;
    for (int i = x; i <= x + 20; i++) {
        if (ok(i, k)) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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