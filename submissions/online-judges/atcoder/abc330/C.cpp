#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll d;
    cin >> d;
    vector<ll> ve;
    ll id = 0;
    while (true) {
        ve.push_back(id * id);
        if (id * id > d) break;
        id++;
    }
    int n = ve.size();
    // cerr << n << '\n';
    ll ans = d;
    for (int i = 0; i < n; i++) {
        ll cur = ve[i];
        // cur + x >= d
        ll p = lower_bound(ve.begin(), ve.end(), d - cur) - ve.begin();
        if (p < n) {
            ans = min(ans, abs(cur + ve[p] - d));
        }
        if (p > 0) {
            ans = min(ans, abs(cur + ve[p - 1] - d));
        }
        // cerr << ans << '\n';
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