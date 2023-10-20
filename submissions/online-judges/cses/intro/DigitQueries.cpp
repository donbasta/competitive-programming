#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        if (k <= 9) {
            cout << k << '\n';
            continue;
        }
        ll dig = 1;
        ll pw10 = 1;
        while (true) {
            ll cnt_dig = 1ll * dig * 9 * pw10;
            if (k > cnt_dig) {
                k -= cnt_dig;
                pw10 *= 10;
                dig++;
            } else {
                break;
            }
        }
        ll bef = k / dig;
        ll sisa = k % dig;
        if (sisa == 0) {
            cout << ((bef + 9) % 10) << '\n';
        } else {
            string lmao = to_string(pw10 + bef);
            cout << lmao[sisa - 1] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}