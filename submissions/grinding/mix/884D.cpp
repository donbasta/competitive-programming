#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    multiset<ll> se;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        se.insert(x);
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    while (true) {
        if (se.size() <= 3) {
            for (auto c : se) {
                ans += c;
            }
            break;
        } else if (se.size() % 2 == 0) {
            ll tmp = 0;
            for (int i = 0; i < 2; i++) {
                tmp += *se.begin();
                se.erase(se.begin());
            }
            ans += tmp;
            se.insert(tmp);
        } else {
            ll tmp = 0;
            for (int i = 0; i < 3; i++) {
                tmp += *se.begin();
                se.erase(se.begin());
            }
            ans += tmp;
            se.insert(tmp);
        }
    }
    cout << ans << '\n';
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