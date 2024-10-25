#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;
const int N = 2e5;

ll fc[N + 5], ifc[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return ((fc[a] * ifc[b]) % MOD) * ifc[a - b] % MOD;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    if (ar[n] != -1 && ar[n] != n) {
        cout << 0 << '\n';
        return;
    }
    ar[n] = n;
    int L = 0;
    ll ans = 1;
    while (L < n) {
        int R = L + 1;
        while (ar[R] == -1) R++;
        if (ar[R] > R) {
            cout << 0 << '\n';
            return;
        }
        if (ar[R] < ar[L] || ar[R] - ar[L] > 2 * (R - L)) {
            cout << 0 << '\n';
            return;
        }
        ll tmp = 0;
        for (int p = 0; p <= ar[R] - ar[L]; p++) {
            ll lmao = 1;
            int q = ar[R] - ar[L] - p;
            lmao = (lmao * C(R - L, p)) % MOD;
            lmao = (lmao * C(R - ar[L] - p, q)) % MOD;
            lmao = (lmao * C(L - ar[L], p)) % MOD;
            lmao = (lmao * C(R - L, q)) % MOD;
            lmao = (lmao * fc[p]) % MOD;
            lmao = (lmao * fc[q]) % MOD;
            tmp = (tmp + lmao) % MOD;
        }
        ans = (ans * tmp) % MOD;
        L = R;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}