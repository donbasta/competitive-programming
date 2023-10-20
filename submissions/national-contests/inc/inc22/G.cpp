#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 8e18;

void solve() {
    int n;
    ll p;
    cin >> n >> p;
    ll mx = p, mn = p;
    while (n--) {
        ll tmx = -INF, tmn = INF;
        char op;
        ll c;
        for (int i = 0; i < 2; i++) {
            cin >> op >> c;
            if (op == '+') {
                tmn = min(tmn, mn + c);
                tmx = max(tmx, mx + c);
            } else if (op == 'x') {
                tmn = min(tmn, mn * c);
                tmn = min(tmn, mx * c);
                tmx = max(tmx, mn * c);
                tmx = max(tmx, mx * c);
            }
        }
        mx = tmx, mn = tmn;
    }
    cout << mx << '\n';
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