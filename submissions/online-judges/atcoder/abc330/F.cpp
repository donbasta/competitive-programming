#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n), px(n), py(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    px[0] = x[0];
    py[0] = y[0];
    for (int i = 1; i < n; i++) {
        px[i] = px[i - 1] + x[i];
        py[i] = py[i - 1] + y[i];
    }

    auto solve = [&](const vector<ll>& ve, const vector<ll>& pve, ll len) -> ll {
        int sz = ve.size();
        ll ans = 1e18;
        for (int i = 0; i < sz; i++) {
            ll ki = i;
            ll r = upper_bound(ve.begin(), ve.end(), ve[i] + len) - ve.begin();
            ll ka = sz - r;
            ll pref = ((i > 0) ? pve[i - 1] : 0);
            ll suf = pve[sz - 1] - pve[r - 1];
            ll tmp = ve[i] * ki - pref;
            tmp += (suf - (ve[i] + len) * ka);
            ans = min(ans, tmp);
        }
        for (int i = 0; i < sz; i++) {
            ll ka = sz - 1 - i;
            ll l = lower_bound(ve.begin(), ve.end(), ve[i] - len) - ve.begin();
            ll ki = l;
            ll pref = ((l > 0) ? pve[l - 1] : 0);
            ll suf = pve[sz - 1] - pve[i];
            ll tmp = ((ve[i] - len) * ki - pref);
            tmp += (suf - ve[i] * ka);
            ans = min(ans, tmp);
        }
        return ans;
    };

    auto ok = [&](ll len) -> bool {
        ll moves = 0;
        ll xx = solve(x, px, len);
        ll yy = solve(y, py, len);
        moves = xx + yy;
        return (moves <= k);
    };

    ll l = 0, r = 1e9;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
        el_psy_congroo();
    }

    return 0;
}