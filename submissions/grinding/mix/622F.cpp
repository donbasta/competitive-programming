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
        if (v < 0) v += MOD;
    }
    friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
    friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
    friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }
    ModInt &operator+=(const ModInt &a) {
        if ((v += a.v) >= MOD) v -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &a) {
        if ((v -= a.v) < 0) v += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &a) {
        v = 1LL * v * a.v % MOD;
        return *this;
    }
    ModInt &operator/=(const ModInt &a) {
        return (*this) *= inverse(a);
    }
    ModInt fpow(long long x) {
        ModInt res = 1, a = v;
        assert(x >= 0);
        for (; x; x /= 2, a *= a)
            if (x & 1) res *= a;
        return res;
    }
    ModInt inv() {
        assert(v != 0);
        return fpow(MOD - 2);
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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<Mint> ifc(k + 5);
    Mint cur = 1;
    ifc[0] = 1;
    for (int i = 1; i <= k + 2; i++) {
        cur *= i;
        ifc[i] = cur.inv();
    }

    vector<Mint> p(k + 5);
    for (int i = 1; i <= k + 2; i++) {
        p[i] = p[i - 1] + Mint(i).fpow(k);
    }
    if (n <= k + 2) {
        cout << p[n] << '\n';
        return;
    }
    Mint num = 1;
    for (int i = 1; i <= k + 2; i++) {
        num *= (n - i);
    }
    Mint ans = 0;
    for (int i = 1; i <= k + 2; i++) {
        Mint tmp = p[i] * num;
        tmp = (tmp * Mint(n - i).inv() * ifc[i - 1] * ifc[k + 2 - i]);
        if (abs(k - i) % 2 == 0) {
            ans += tmp;
        } else {
            ans -= tmp;
        }
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
