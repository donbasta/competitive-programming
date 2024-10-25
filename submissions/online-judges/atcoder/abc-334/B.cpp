#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

ll floor(ll a, ll b) {
    if (a % b == 0) return a / b;
    if (a > 0) return a / b;
    return a / b - 1;
}

ll ceil(ll a, ll b) {
    if (a % b == 0) return a / b;
    if (a > 0) return (a + b - 1) / b;
    return a / b;
}

void el_psy_congroo() {
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll R = floor(r - a, m);
    ll L = ceil(l - a, m);
    cout << max(0ll, R - L + 1) << '\n';
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