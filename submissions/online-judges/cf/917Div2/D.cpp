#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;
const int B = 20;

struct BIT {
    vector<ll> tree;
    int n;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int v, int val) {
        while (v <= n) tree[v] = (tree[v] + val) % MOD, v += v & -v;
    }
    ll get(int v) {
        ll ret = 0;
        while (v) ret = (ret + tree[v]) % MOD, v -= v & -v;
        return ret;
    }
};

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<ll> P(n + 1), Q(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> Q[i];
        Q[i]++;
    }
    BIT iq(k), in(2 * n);
    ll inv_q = 0;
    for (int i = 1; i <= k; i++) {
        inv_q = (inv_q + i - 1 - iq.get(Q[i])) % MOD;
        iq.upd(Q[i], 1);
    }
    ll ans = (1ll * n * inv_q) % MOD;

    auto calc = [&](int j) -> ll {
        ll ret;
        if (j + 1 >= k) {
            ret = (1ll * k * k) % MOD;
        } else if (j + 1 >= 1) {
            ret = (1ll * j * k + 1ll * (k + j + 1) * (k - j) / 2) % MOD;
        } else if (j + k >= 1) {
            ret = (1ll * (j + k) * (j + k + 1) / 2) % MOD;
        } else if (j + k <= 0) {
            ret = 0;
        }
        return ret;
    };

    for (int i = n; i >= 1; i--) {
        for (int j = -B; j <= B; j++) {
            ll L, R;
            if (j >= 0) {
                R = (P[i] - 1) / (1ll << j);
                L = (P[i] + (1ll << (j + 1)) - 1) / (1ll << (j + 1));
            } else {
                R = P[i] * (1ll << (-j)) - 1;
                L = (P[i] * (1ll << ((-j) - 1)));
            }
            if (L > R) continue;
            ll cnt = in.get(min(2ll * n, R)) - in.get(min(2ll * n, L - 1));

            ll lmao = calc(j);
            ans = (ans + cnt * lmao) % MOD;
        }
        in.upd(P[i], 1);
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
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