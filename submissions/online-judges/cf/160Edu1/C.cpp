#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    vector<int> ve(31);
    int m;
    cin >> m;
    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            ve[v]++;
        } else {
            bool ok = true;
            vector<int> cp = ve;
            for (int i = 0; i < 30; i++) {
                if ((v >> i) & 1) {
                    if (cp[i] == 0) {
                        ok = false;
                        break;
                    }
                    cp[i]--;
                }
                cp[i + 1] += cp[i] / 2;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}