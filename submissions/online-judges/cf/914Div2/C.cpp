#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ll min_sel = INF;
    for (int i = 1; i < n; i++) {
        min_sel = min(min_sel, ar[i] - ar[i - 1]);
    }
    if (k == 1) {
        cout << min(min_sel, ar[0]) << '\n';
    } else if (k >= 3) {
        cout << 0 << '\n';
    } else {
        ll ans = min(min_sel, ar[0]);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll tmp = ar[j] - ar[i];
                int x = upper_bound(ar.begin(), ar.end(), tmp) - ar.begin();
                if (x < n) ans = min(ans, ar[x] - tmp);
                if (x > 0) ans = min(ans, tmp - ar[x - 1]);
            }
        }
        cout << ans << '\n';
    }
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