#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int x, y, k;
    cin >> x >> y >> k;
    int ans;
    if (y <= x) {
        ans = x;
    } else if (x + k >= y) {
        ans = y;
    } else {
        ans = x + k + 2 * (y - x - k);
    }
    cout << ans << '\n';
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