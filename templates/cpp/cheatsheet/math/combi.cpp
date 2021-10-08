const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Combi {
    vector<ll> fc, ifc;
    void init(int n) {
        fc.resize(n + 5), ifc.resize(n + 5);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (fc[i - 1] * i) % MOD;
        }
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
        }
    }
    ll cb(ll a, ll b) {
        if (a < 0 || b < 0 || a < b) {
            return 0;
        }
        ll ret = (fc[a] * ifc[b]) % MOD;
        ret = (ret * ifc[a - b]) % MOD;
        return ret;
    }
} combi;