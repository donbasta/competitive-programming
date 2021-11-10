#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<int MOD>
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
    ModInt& operator+=(const ModInt &a) {
        if ((v += a.v) >= MOD) v -= MOD;
        return *this; 
    }
    ModInt& operator-=(const ModInt &a) {
        if ((v -= a.v) < 0) v += MOD;
        return *this; 
    }
    ModInt& operator*=(const ModInt &a) {
        v = 1ll * v * a.v % MOD;
        return *this; 
    }
    ModInt& operator/=(const ModInt &a) {
        return (*this) *= inverse(a); 
    }
 
    friend ModInt fpow(ModInt a, long long x) {
        ModInt res = 1; assert(x >= 0);
        for (; x; x /= 2, a *= a) if (x & 1) res *= a;
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
 
    friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
    friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};
 
const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

const int N = 2e5;
Mint fc[N + 5], ifc[N + 5];

Mint fpow(Mint a, long long x);
Mint inverse(Mint a);
Mint C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return fc[a] * ifc[a - b] * ifc[b];
}
void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = fc[i - 1] * i;
    } 
    ifc[N] = inverse(fc[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1);
    }
}

void solve () {
    init();

    int n, k;
    cin >> n >> k;
    Mint W = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        W += w;
    }

    const auto stir = [&](int elem, int subset) -> Mint {
        Mint ret = 0;
        Mint mul = 1;
        for (int i = 0; i <= subset; i++) {
            Mint tmp = C(subset, i) * fpow((subset - i), elem) * mul;
            ret += tmp;
            mul *= -1;
        }
        ret /= fc[subset];
        return ret;
    };

    Mint coef = stir(n, k) + stir(n - 1, k) * (n - 1);
    Mint ans = W * coef;
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}