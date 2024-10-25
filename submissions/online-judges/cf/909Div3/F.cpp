#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<int> que(q);
    for (int i = 0; i < q; i++) {
        cin >> que[i];
    }
    for (int i = 1; i < n; i++) {
        cout << i << ' ' << (i + 1) << '\n';
    }
    int ne = n - 1;
    for (int i = 0; i < q; i++) {
        int now = que[i];
        if (ne == n - 1) {
            if (now == n - 1) {
                cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
            } else {
                cout << n << ' ' << ne << ' ' << now << '\n';
                ne = now;
            }
        } else {
            if (now == ne || now == n - ne) {
                cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
            } else {
                cout << n << ' ' << ne << ' ' << now << '\n';
                ne = now;
            }
        }
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