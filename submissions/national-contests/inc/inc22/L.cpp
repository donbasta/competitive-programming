#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

template <int MOD>
class ModInt {
   public:
    int v;
    ModInt() : v(0) {}
    ModInt(long long _v) {
        v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
        if (v < 0)
            v += MOD;
    }
    friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
    friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
    friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }
    ModInt &operator+=(const ModInt &a) {
        if ((v += a.v) >= MOD)
            v -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &a) {
        if ((v -= a.v) < 0)
            v += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &a) {
        v = 1ll * v * a.v % MOD;
        return *this;
    }
    ModInt &operator/=(const ModInt &a) {
        return (*this) *= inverse(a);
    }
    friend ModInt fpow(ModInt a, long long x) {
        ModInt res = 1;
        assert(x >= 0);
        for (; x; x /= 2, a *= a)
            if (x & 1)
                res *= a;
        return res;
    }
    friend ModInt inverse(ModInt a) {
        assert(a.v != 0);
        return fpow(a, MOD - 2);
    }

    ModInt operator+() const { return ModInt(v); }
    ModInt operator-() const { return ModInt(-v); }
    ModInt operator++() const { return *this += 1; }
    ModInt operator--() const { return *this -= 1; }

    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

    friend istream &operator>>(istream &is, ModInt &v) {
        is >> v.v;
        return is;
    }
    friend ostream &operator<<(ostream &os, const ModInt &v) {
        os << v.v;
        return os;
    }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

void solve() {
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    vector<Mint> len(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        len[i] = R[i] - L[i] + 1;
    }
    vector<int> P(n), Q(n), X(n), Y(n);
    for (int i = 0; i < n - 1; i++) {
        P[i] = max(L[i], L[i + 1]);
        Q[i] = min(R[i], R[i + 1]);
    }
    for (int i = 0; i < n - 2; i++) {
        X[i] = max(P[i], P[i + 1]);
        Y[i] = min(Q[i], Q[i + 1]);
    }
    Mint ans = 0;
    const function<Mint(Mint)> sum_sq = [&](Mint x) -> Mint {
        return x * (x + 1) * (x * 2 + 1) / 6;
    };
    for (int i = 0; i < n - 1; i++) {
        if (P[i] > Q[i]) continue;
        Mint tmp = sum_sq(Q[i]) - sum_sq(P[i] - 1);
        tmp /= (len[i] * len[i + 1]);
        ans += tmp;
    }
    for (int i = 0; i < n - 2; i++) {
        if (X[i] > Y[i]) continue;
        Mint tmp = sum_sq(Y[i]) - sum_sq(X[i] - 1);
        tmp /= (len[i] * len[i + 1] * len[i + 2]);
        ans += (tmp * 2);
    }
    vector<Mint> S(n);
    Mint lol = 0;
    for (int i = 0; i < n - 1; i++) {
        if (P[i] > Q[i]) continue;
        S[i] = (1ll * (Q[i] + P[i]) * (Q[i] - P[i] + 1) / 2) % MOD;
        S[i] /= (len[i] * len[i + 1]);
        lol += S[i];
    }
    lol = lol * lol;
    for (int i = 0; i < n - 1; i++) {
        lol -= (S[i] * S[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        lol -= (S[i] * S[i + 1] * 2);
    }
    ans += lol;
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
