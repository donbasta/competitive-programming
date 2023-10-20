#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<long long>;
using uint = unsigned int;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

const int INF = 2e9;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

template <uint MD>
struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M &set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M &r) const { return M().set_v(v + r.v); }
    M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M &r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M &r) const { return *this * r.inv(); }
    M &operator+=(const M &r) { return *this = *this + r; }
    M &operator-=(const M &r) { return *this = *this - r; }
    M &operator*=(const M &r) { return *this = *this * r; }
    M &operator/=(const M &r) { return *this = *this / r; }
    bool operator==(const M &r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;
template <>
const Mint Mint::G = Mint(3);

template <class Mint>
void nft(bool type, V<Mint> &a) {
    int n = int(a.size()), s = 0;
    while ((1 << s) < n)
        s++;
    assert(1 << s == n);

    static V<Mint> ep, iep;
    while (int(ep.size()) <= s) {
        ep.push_back(Mint::G.pow(Mint(-1).v / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }
    V<Mint> b(n);
    for (int i = 1; i <= s; i++) {
        int w = 1 << (s - i);
        Mint base = type ? iep[i] : ep[i], now = 1;
        for (int y = 0; y < n / 2; y += w) {
            for (int x = 0; x < w; x++) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        swap(a, b);
    }
}

template <class Mint>
V<Mint> multiply(const V<Mint> &a, const V<Mint> &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};
    int lg = 0;
    while ((1 << lg) < n + m - 1)
        lg++;
    int z = 1 << lg;
    auto a2 = a, b2 = b;
    a2.resize(z);
    b2.resize(z);
    nft(false, a2);
    nft(false, b2);
    for (int i = 0; i < z; i++)
        a2[i] *= b2[i];
    nft(true, a2);
    a2.resize(n + m - 1);
    Mint iz = Mint(z).inv();
    for (int i = 0; i < n + m - 1; i++)
        a2[i] *= iz;
    return a2;
}

V<Mint> operate(const V<Mint> &a, const V<Mint> &b, int m) {
    V<Mint> X = multiply(a, b);
    int sz = X.size();
    if (sz > m) {
        for (int i = m; i < sz; i++) {
            X[i - m] += X[i];
        }
        X.resize(m);
    }
    return X;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ll pw = fpow(2, k, MOD - 1);
    V<Mint> P(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        P[x] += 1;
    }
    V<Mint> ret = {1};

    while (pw) {
        if (pw & 1) {
            ret = operate(ret, P, m);
        }
        P = operate(P, P, m);
        pw >>= 1;
    }

    Mint ans = 0;
    int sz = ret.size();
    for (int i = 0; i < min(m, sz); i++) {
        ans += ret[i] * i;
    }
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
