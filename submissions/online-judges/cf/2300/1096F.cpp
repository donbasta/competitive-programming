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
 
const int MOD = 998244353;
using Mint = ModInt<MOD>;

Mint countInversion(const vector<int>& ve, int n) {
    vector<Mint> bit(n + 1);
    const auto get = [&](int a) -> Mint {
        Mint ret = 0;
        while (a) {
            ret += bit[a];
            a -= a & (-a);
        }
        return ret;
    };
    const auto upd = [&](int a, int val) -> void {
        while (a <= n) {
            bit[a] += val;
            a += a & (-a);
        }
    };
    Mint ret = 0;
    for (int i = 0; i < ve.size(); i++) {
        ret += get(n) - get(ve[i] - 1);
        upd(ve[i], 1);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    int ksg = 0;
    vector<bool> udah(n);
    vector<int> ve, blm, p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == -1) {
            ksg++;
            ve.emplace_back(i);
        } else {
            udah[--p[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!udah[i]) {
            blm.emplace_back(i);
        }
    }
    vector<int> init;
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            cerr << p[i] << '\n';
            init.emplace_back(p[i] + 1);
        }
    }
    Mint exp = countInversion(init, n);
    if (ksg == 0) {
        cout << exp << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        int d = lower_bound(ve.begin(), ve.end(), i) - ve.begin();
        int u = ve.size() - (upper_bound(ve.begin(), ve.end(), i) - ve.begin());
        if (p[i] != -1) {
            int choose1 = blm.size() - (upper_bound(blm.begin(), blm.end(), p[i]) - blm.begin());
            int choose2 = lower_bound(blm.begin(), blm.end(), p[i]) - blm.begin();
            Mint add = (Mint(d) * Mint(choose1) / Mint(ksg)) + (Mint(u) * Mint(choose2) / Mint(ksg));
            exp += add;
        } else {
            Mint add = (Mint(d) / Mint(2)); 
            exp += add;
        }
    }
    cout << exp << '\n';
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