#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), br(n), cr(n), suf(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++) {
        br[i] = ar[i] + i;
        cr[i] = ar[i] - i + (n - 1);
    }
    pref[0] = cr[0];
    for (int i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], cr[i]);
    }
    suf[n - 1] = br[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], br[i]);
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ll ki = (i > 0 ? pref[i - 1] : 0);
        ll ka = (i < n - 1 ? suf[i + 1] : 0);
        ll cur = max(ki, ka);
        cur = max(cur, ar[i]);
        ans = min(ans, cur);
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