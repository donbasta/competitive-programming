#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int mask = (1 << 6) - 1;
    int ans = 0;
    for (int i = 0; i < (1 << 6); i++) {
        for (int j = i; j < (1 << 6); j++) {
            if ((i | j) == mask) {
                ans++;
            }
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
        solve();
    }

    return 0;
}