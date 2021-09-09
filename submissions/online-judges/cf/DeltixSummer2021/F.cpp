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
 
    friend ModInt pow(ModInt a, long long x) {
        ModInt res = 1; assert(x >= 0);
        for (; x; x /= 2, a *= a) if (x & 1) res *= a;
        return res; 
    }
    friend ModInt inverse(ModInt a) {
        assert(a.v != 0);
        return pow(a, MOD - 2); 
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

int n;

void solve() {
    cin >> n;
    vector<Mint> ar(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ar[i] = x;
    }
    Mint ans = 0;
    for (int i = 0; i < n; i++) {
        vector<Mint> dp(1 << n);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            vector<Mint> ndp(1 << n);
            for (int k = 0; k < (1 << (j + 1)); k++) {
                if ((k & (1 << i))) continue;
                vector<int> on, off;
                for (int l = 0; l <= j; l++) {
                    if (l == i) continue;
                    if ((k & (1 << l))) on.push_back(l);
                    else off.push_back(l);
                }
                if ((k & (1 << j))) {
                    Mint temp = ar[i] / (ar[i] + ar[j]);
                    for (auto c : off) {
                        temp *= (ar[c] / (ar[c] + ar[j]));
                    }
                    Mint impos = 1;
                    for (auto c : on) {
                        impos *= (ar[j] / (ar[c] + ar[j]));
                    }
                    Mint temp2 = 1 - impos;
                    temp2 *= (ar[j] / (ar[i] + ar[j]));
                    temp += temp2;
                    ndp[k] = dp[k ^ (1 << j)] * temp;
                } else {
                    Mint temp = ar[j] / (ar[i] + ar[j]);
                    for (auto c : on) {
                        temp *= (ar[j] / (ar[c] + ar[j]));
                    }
                    ndp[k] = dp[k] * temp;
                }
                // cerr << i << ' ' << j << ' ' << k << ' ' << ndp[k] << '\n';
            }
            for (int k = 0; k < (1 << (j + 1)); k++) {
                dp[k] = ndp[k];
            }
            // if (i == 0 && j == 1) {
            //     cerr << i << ' ' << j << ' ';
            //     cerr << dp[0] << ' ' << dp[2] << '\n';
            // }
            // if (i == 0 && j == 2) {
            //     cerr << i << ' ' << j << ' ';
            //     cerr << dp[0] << ' ' << dp[2] << ' ' << dp[4] << ' ' << dp[6] << '\n';
            // }
        }
        // cerr << i << ' ' << dp[((1 << n) - 1) ^ (1 << i)] << '\n';
        ans += dp[((1 << n) - 1) ^ (1 << i)];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}