#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll tot = 0;
    for (int i = 0; i < 5; i++) {
        ll a, b;
        cin >> a >> b;
        tot += (a * b);
    }
    ll x, y;
    cin >> x >> y;
    tot /= 5;
    ll ans = (x * tot) / y;
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