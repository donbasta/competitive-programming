#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ve;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        ve.emplace_back(l, r);
    }
    ll lo = 0, hi = INF;
    ll ans = -1;

    auto ok = [&](ll k) -> bool {
        ll cl = 0, cr = 0;
        for (int i = 0; i < n; i++) {
            cl -= k, cr += k;
            if (cl > ve[i].second || cr < ve[i].first) {
                return false;
            }
            cl = max(cl, ve[i].first);
            cr = min(cr, ve[i].second);
        }
        return true;
    };

    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    assert(ans != -1);
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