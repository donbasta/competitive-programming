#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll B = 31;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct BIT {
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n + 5) {}
    void upd(int l, ll val) {
        l++;
        while (l <= n) {
            bit[l] = (bit[l] + val) % MOD;
            l += l & -l;
        }
    }
    void upd(int l, int r, ll val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    ll get(int idx) {
        ll ret = 0;
        idx++;
        while (idx > 0) {
            ret = (ret + bit[idx]) % MOD;
            idx -= idx & -idx;
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<ll> ipw(n + 1), pw(n + 1), s1(n), s2(n);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] * B) % MOD;
    }
    ll iB = fpow(B, MOD - 2);
    ipw[0] = 1;
    for (int i = 1; i <= n; i++) {
        ipw[i] = (ipw[i - 1] * iB) % MOD;
    }
    for (int i = 0; i < n; i++) {
        int cur_dig = (s[i] - 'a' + 1);
        s1[i] = ((1ll * cur_dig * pw[i]) + (i ? s1[i - 1] : 0)) % MOD;
    }
    for (int i = n - 1; i >= 0; i--) {
        int cur_dig = (s[i] - 'a' + 1);
        s2[i] = ((1ll * cur_dig * pw[n - 1 - i]) + (i < n - 1 ? s2[i + 1] : 0)) % MOD;
    }
    BIT sgt1(n), sgt2(n);
    for (int i = 0; i < n; i++) {
        sgt1.upd(i, i, s1[i]);
        sgt2.upd(i, i, s2[i]);
    }

    auto get1 = [&](int x, int y) -> ll {
        ll yy = sgt1.get(y);
        ll xx = (x ? sgt1.get(x - 1) : 0);
        ll ret = (1ll * (yy - xx) * ipw[x]) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    };
    auto get2 = [&](int x, int y) -> ll {
        ll xx = sgt2.get(x);
        ll yy = (y < n - 1 ? sgt2.get(y + 1) : 0);
        ll ret = (1ll * (xx - yy) * ipw[n - 1 - y]) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    };

    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            ll n1 = (1ll * (c - s[x]) * pw[x]) % MOD;
            ll n2 = (1ll * (c - s[x]) * pw[n - 1 - x]) % MOD;
            s[x] = c;
            sgt1.upd(x, n - 1, n1);
            sgt2.upd(0, x, n2);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            bool ans;
            if (l == r) {
                ans = true;
            } else {
                int length = (r - l + 1);
                int a, b;
                if (length & 1) {
                    a = ((l + r) / 2) - 1;
                    b = ((l + r) / 2) + 1;
                } else {
                    a = ((l + r) / 2);
                    b = ((l + r) / 2) + 1;
                }
                ll ki = get1(l, a);
                ll ka = get2(b, r);
                ans = (ki == ka);
            }
            cout << (ans ? "Yes" : "No") << '\n';
        }
    }
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