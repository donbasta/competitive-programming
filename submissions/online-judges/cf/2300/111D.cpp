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
        v = 1LL * v * a.v % MOD;
        return *this; 
    }
    ModInt& operator/=(const ModInt &a) {
        return (*this) *= inv(a); 
    }
    friend ModInt fpow(ModInt a, long long x) {
        ModInt res = 1; assert(x >= 0);
        for (; x; x /= 2, a *= a) if (x & 1) res *= a;
        return res; 
    }
    friend ModInt inv(ModInt a) {
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
const int N = 1e6;
Mint fc[N + 5], ifc[N + 5];

Mint fpow(Mint a, long long x);
Mint inv(Mint a);

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = fc[i - 1] * i;
    }
    ifc[N] = inv(fc[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1);
    }
}

Mint C(int a, int b) {
    if (a < b || a < 0 || b < 0) {
        return 0;
    }
    return fc[a] * ifc[b] * ifc[a - b];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
        cout << fpow(k, n) << '\n';
        return;
    }
    vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = fc[i];
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) * i;
        }
    }
    if (m == 2) {
        Mint ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += C(k, i) * C(k, i) * dp[i][n] * dp[i][n];
        }
        cout << ans << '\n';
        return;
    }
    Mint ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            Mint tmp = fpow(i, n * (m - 2)) * dp[j + i][n] * dp[j + i][n];
            tmp *= C(k, i) * C(k - i, j) * C(k - i - j, j);
            ans += tmp;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}