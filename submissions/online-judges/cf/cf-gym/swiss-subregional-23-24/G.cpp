#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll d;
    cin >> d;
    d *= 2;
    vector<pair<ll, ll>> ret;
    for (ll i = 1; i * i <= d; i++) {
        if (d % i != 0) continue;
        ll x = i, y = d / i;
        if ((y - x) % 2 == 0) continue;
        if (y == (x + 1)) continue;
        ret.emplace_back((y - x - 1) / 2, (y + x - 1) / 2);
    }
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << e.first << ' ' << e.second << '\n';
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