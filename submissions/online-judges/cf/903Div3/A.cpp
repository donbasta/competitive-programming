#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    int cn = n;
    string x, s;
    cin >> x >> s;
    int step = 0;
    while (true) {
        if (n > 3 * max(m, cn)) break;
        if (n < m) {
            x += x;
            n *= 2;
            step++;
            continue;
        } else {
            for (int i = 0; i <= min(cn - 1, n - m); i++) {
                if (x.substr(i, m) == s) {
                    cout << step << '\n';
                    return;
                }
            }
            x += x;
            n *= 2;
            step++;
        }
    }
    cout << -1 << '\n';
    return;
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