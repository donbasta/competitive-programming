#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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
    int A = 0;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        A += ar[i];
    }
    vector<Mint> f(A + 1);
    f[0] = n - 1;
    Mint ia = Mint(1) / A;
    Mint in = Mint(1) / (n - 1);
    for (int i = 1; i <= A - 1; i++) {
        f[i] = f[i - 1] * i * ia + 1;
        f[i] /= ((Mint(1) - ia * i) * in);
    }
    for (int i = A - 1; i >= 0; i--) {
        f[i] += f[i + 1];
    }

    Mint E = 0;
    for (int i = 0; i < n; i++) {
        E += f[ar[i]];
    }
    E -= f[0] * (n - 1);
    E /= n;
    cout << E << '\n';
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