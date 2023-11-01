#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void el_psy_congroo() {
    ll a, b, c, v6, v9;
    cin >> a >> b >> c;
    ll fpb = __gcd(a, b);
    a /= fpb, b /= fpb;
    v6 = 1;
    v9 = a + b;

    if (c >= b) {
        cout << b << '\n';
        return;
    }

    ll x, y;
    ll g = gcd(a, b, x, y);
    assert(g == 1);

    if (c <= 1e7) {
        for (int i = 1; i <= c; i++) {
            ll v13 = (a * i) % b;
            if (v13 * 2 > b) v13 -= b;
            v13 = abs(v13);
            ll v17 = v13 * v6 - v9 * i;
            if (v17 < 0) {
                v6 = i;
                v9 = v13;
            }
        }
        cout << v6 << '\n';
    } else {
        if (c >= b) {
            cout << b << '\n';
        } else {
            ll tes = 3e7;
            ll aa = a * c % b;
            if (aa * 2 > b) aa = b - aa;
            pair<ll, ll> mn = make_pair(aa, c);
            ll idx = 1;
            ll x = c - 1;
            ll bat = max(b / 2, c - tes);
            while (x >= bat) {
                ll t = a * x % b;
                if (t * 2 > b) t = b - t;
                if (t * mn.second < x * mn.first) {
                    idx = x;
                    mn = make_pair(t, x);
                }
                x--;
            }
            // for (ll i = 1; i <= tes; i++) {
            //     ll t = (x * i) % b;
            //     ll mx = max(t, b - t);
            //     if (mx > c) mx = min(t, b - t);
            //     if (mx > c) continue;
            //     if (i * mn.second < mx * mn.first) {
            //         mn = make_pair(i, mx);
            //         idx = mx;
            //     }
            // }
            // for (ll i = b / 2; i >= max(0ll, b / 2 - tes); i--) {
            //     ll j = i * x % b;
            //     ll mx = max(j, b - j);
            //     ll lmao = mx;
            //     if (lmao > c) {
            //         lmao = min(j, b - j);
            //     }
            //     if (lmao > c) {
            //         continue;
            //     }
            //     if (i * mn.second < lmao * mn.first) {
            //         mn = make_pair(i, lmao);
            //         idx = lmao;
            //     }
            // }
            cout << idx << '\n';
        }
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