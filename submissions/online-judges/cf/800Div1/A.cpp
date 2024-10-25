#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ve(n), c0(n + 1);
    for (auto& e : ve) cin >> e;
    for (int i = n - 1; i >= 0; i--) {
        c0[i] = (c0[i + 1] + (ve[i] == 0));
    }
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += ve[i];
        if (cur < 0) {
            cout << "No" << '\n';
            return;
        }
        if (cur == 0) {
            if (c0[i + 1] < n - i - 1) {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << ((cur == 0) ? "Yes" : "No") << '\n';
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
