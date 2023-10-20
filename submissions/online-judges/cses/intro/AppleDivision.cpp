#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    ll ans = 1e18;
    for (int i = 0; i < (1 << n); i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1)
                tmp += p[j];
            else
                tmp -= p[j];
        }
        ans = min(ans, abs(tmp));
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