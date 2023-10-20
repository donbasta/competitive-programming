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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    int slot = 0;
    unordered_map<int, int> cnt;
    set<int> ada;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == -1)
            slot++;
        else {
            cnt[ar[i]]++;
            ada.insert(ar[i]);
        }
    }
    unordered_map<int, int> se;
    for (auto x : ada) {
        se[cnt[x]]++;
    }
    se[0] = (k - ada.size());
    vector<Mint> f(n + 1);
    f[0] = k;
    for (int i = 1; i <= n - 1; i++) {
        f[i] = (Mint(n) * k + Mint(i) * (k - 1) * f[i - 1]) / (n - i);
    }
    for (int i = n - 1; i >= 0; i--) {
        f[i] += f[i + 1];
    }
    Mint E = 0;
    vector<Mint> pw(slot + 1);
    pw[0] = 1;
    for (int i = 1; i <= slot; i++) {
        pw[i] = pw[i - 1] * (k - 1);
    }
    vector<Mint> fc(n + 1), ifc(n + 1);
    Mint invk = Mint(1) / k;
    Mint invk_slot = 1;  // k^(-slot)
    for (int i = 1; i <= slot; i++) invk_slot *= invk;
    fc[0] = 1;
    for (int i = 1; i <= n; i++) fc[i] = fc[i - 1] * i;
    ifc[n] = Mint(1) / fc[n];
    for (int i = n - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1);
    auto cb = [&](int a, int b) -> Mint {
        if (a < 0 || b < 0 || a < b) return 0;
        return fc[a] * ifc[b] * ifc[a - b];
    };
    for (auto e : se) {
        int x = e.first, y = e.second;
        Mint tmp = 0;
        for (int i = x; i <= x + slot; i++) {
            tmp += f[i] * pw[slot + x - i] * cb(slot, i - x);
        }
        E += tmp * y * invk_slot;
    }
    E -= f[0] * (k - 1);
    E /= k;
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