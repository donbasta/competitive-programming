const int N = 2e6;
const ll MOD = 998244353;

ll fc[2 * N + 5], ifc[2 * N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

inline ll inv(ll a) { return fpow(a, MOD - 2); }

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = inv(fc[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a];
    ret = (ret * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}