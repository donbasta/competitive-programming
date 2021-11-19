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
 
Mint fpow(Mint a, long long x);
Mint inverse(Mint a);
 
const int M = 400;
 
Mint pick(ll a, ll b) {
    Mint ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= (a - i);
    }
    return ret;
}
 
void solve () {
    int n, k;
    cin >> n >> k;
 
    int sz = min(n, M);
    vector<Mint> pick(sz + 1);
    pick[0] = 1;
    pick[1] = n;
    for (int i = 2; i <= sz; i++) {
        pick[i] = pick[i - 1] * (n - i + 1) / i;
    }
 
    vector<vector<Mint>> f(sz + 1, vector<Mint>(sz + 1));
    f[0][0] = 1;
    for (int i = 2; i <= sz; i++) {
        for (int j = 1; j * 2 <= i; j++) {
            f[i][j] = f[i - 2][j - 1] * (i - 1) + f[i - 1][j] * (i - 1);
            cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
        }
    }
 
    vector<Mint> dp(k + 1), ans(k + 1);
    for (int i = 0; i <= k; i++) {
        for (int j = i; j <= sz; j++) {
            dp[i] += f[j][j - i] * pick[j];
            cerr << i << ' ' << j << ' ' << dp[i] << '\n';
        }
        cerr << i << ' ' << dp[i] << '\n';
    }
    ans[0] = dp[0];
    ans[1] = dp[1];
    for (int i = 2; i <= k; i++) {
        ans[i] = ans[i - 2] + dp[i];
    }
    for (int i = 1; i <= k; i++) {
        cout << ans[i] << " \n"[i == k];
    }
    return;
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