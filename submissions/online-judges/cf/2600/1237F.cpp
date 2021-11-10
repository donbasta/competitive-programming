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
 
const int MOD = 998244353;
using Mint = ModInt<MOD>;

Mint inverse(Mint a);

const int M = 3600;
Mint fc[M + 5], ifc[M + 5];

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= M; i++) {
        fc[i] = fc[i - 1] * i;
    }
    ifc[M] = inverse(fc[M]);
    for (int i = M - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1);
    }
}

Mint pick(int a, int b) {
    if (a < 0 || a < b) return 0;
    return (fc[a] * ifc[a - b]);
}

void solve () {
    int h, w, n;
    cin >> h >> w >> n;
    vector<bool> H(h + 1), W(w + 1);
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        H[r1] = H[r2] = true;
        W[c1] = W[c2] = true;
    }
    int A = 0, B = 0;
    for (int i = 1; i <= h; i++) {
        A += (int) H[i];
    }
    for (int i = 1; i <= w; i++) {
        B += (int) W[i];
    }

    vector<vector<Mint>> dp1(h + 1, vector<Mint>(h + 1));
    vector<vector<Mint>> dp2(w + 1, vector<Mint>(w + 1));
    dp1[0][0] = dp2[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        dp1[i][0] = 1;
        for (int j = 1; j * 2 <= i; j++) {
            dp1[i][j] += dp1[i - 1][j];
            if (i >= 2 && !H[i] && !H[i - 1]) {
                dp1[i][j] += dp1[i - 2][j - 1];
            }
        }
    }
    for (int i = 1; i <= w; i++) {
        dp2[i][0] = 1;
        for (int j = 1; j * 2 <= i; j++) {
            dp2[i][j] += dp2[i - 1][j];
            if (i >= 2 && !W[i] && !W[i - 1]) {
                dp2[i][j] += dp2[i - 2][j - 1];
            }
        }
    }
    Mint ret = 0;
    for (int i = 0; 2 * i <= h; i++) {
        for (int j = 0; 2 * j <= w; j++) {
            ret += dp1[h][i] * dp2[w][j] * pick(w - B - 2 * j, i) * pick(h - A - 2 * i, j);
        }
    }
    cout << ret << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}