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
 
    ModInt operator+() const { return ModInt(v); }
    ModInt operator-() const { return ModInt(-v); }
 
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
 
    friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
    friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};
 
const int MOD = 998244353;
using Mint = ModInt<MOD>;

int n;

void solve() {
    cin >> n;
    vector<Mint> dp(n + 1), pd(n + 1), pdr(n + 1);
    vector<ll> x(n + 1), y(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    if (s[1] == 0) dp[1] = (x[1] + 1);
    else if (s[1] == 1) dp[1] = (x[1] * 2 - y[1] + 1);
    pd[1] = (x[1] + 1 - y[1]);
    pdr[1] = pd[1];

    for (int i = 2; i <= n; i++) {
        int j = upper_bound(x.begin(), x.end(), y[i]) - x.begin();
        pd[i] = (pdr[i - 1] - pdr[j - 1] + x[i] - y[i] + 1 - (i - j));
        pdr[i] = (pdr[i - 1] + pd[i]); 
    }

    for (int i = 2; i <= n; i++) {
        if (s[i] == 0) {
            dp[i] = dp[i - 1] + (x[i] - x[i - 1]);
        } else if (s[i] == 1) {
            dp[i] = dp[i - 1] + (x[i] - x[i - 1] - 1) + pd[i];
        }
    }

    cout << dp[n] << '\n';
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