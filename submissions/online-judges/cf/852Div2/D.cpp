#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll choose(ll k) {
    if (k <= 0) return 0;
    return k * (k + 1) / 2;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n), q(n), P(n), Q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        P[--p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        Q[--q[i]] = i;
    }
    ll ans = 0;
    ll u = P[0], v = Q[0];
    if (u > v) swap(u, v);
    ans += choose(u);
    ans += choose(v - 1 - u);
    ans += choose(n - 1 - v);
    ll ul = u, ur = u, vl = v, vr = v;

    for (int i = 1; i < n; i++) {
        ll ml = min(ul, vl), mr = max(ur, vr);
        ll pp = P[i], qq = Q[i];
        if (pp >= ml && pp <= mr) {
            ul = min(ul, pp), ur = max(ur, pp);
            vl = min(vl, qq), vr = max(vr, qq);
            continue;
        };
        if (qq >= ml && qq <= mr) {
            ul = min(ul, pp), ur = max(ur, pp);
            vl = min(vl, qq), vr = max(vr, qq);
            continue;
        };

        ll pp1 = pp, qq1 = qq;
        if (pp1 > qq1) swap(pp1, qq1);
        if (pp1 < ml && qq1 < ml) {
            ans += (ml - qq1) * (n - mr);
        } else if (pp1 > mr && qq1 > mr) {
            ans += (ml + 1) * (pp1 - mr);
        } else {
            ans += (ml - pp1) * (qq1 - mr);
        }

        ul = min(ul, pp), ur = max(ur, pp);
        vl = min(vl, qq), vr = max(vr, qq);
    }
    ans++;
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