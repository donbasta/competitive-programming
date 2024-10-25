#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int l, r;
    cin >> l >> r;
    int cnt = (r - l + 1);
    ll all = 1ll * cnt * (cnt - 1) * (cnt - 2) / 6;
    ll c1 = 0, c2 = 0;
    c2 = max(0ll, (r / 6) - ((l + 2) / 3) + 1);
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