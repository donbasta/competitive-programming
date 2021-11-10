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

struct BIT {
    int n;
    vector<Mint> bit;
    BIT(int _n) : n(_n) {
        bit.resize(n + 1);
    }
    void upd(int pos, Mint val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += (pos & (-pos));
        }
    }
    Mint get(int pos) {
        Mint ret = 0;
        while (pos > 0) {
            ret += bit[pos];
            pos -= (pos & (-pos));
        }
        return ret;
    }
    Mint get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve () {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<pair<int, int>> ve(n);
    {
        deque<pair<int, int>> de;
        for (int i = 1; i <= n; i++) {
            while (!de.empty() && de.back().first > ar[i]) {
                ve[de.back().second - 1].second = i - 1;
                de.pop_back();
            }
            de.push_back(make_pair(ar[i], i));
        }
        while (!de.empty()) {
            ve[de.back().second - 1].second = n;
            de.pop_back();
        }
    }
    {
        deque<pair<int, int>> de;
        for (int i = n; i >= 1; i--) {
            while (!de.empty() && de.back().first > ar[i]) {
                ve[de.back().second - 1].first = i + 1;
                de.pop_back();
            }
            de.push_back(make_pair(ar[i], i));
        }
        while (!de.empty()) {
            ve[de.back().second - 1].first = 1;
            de.pop_back();
        }
    }

    BIT bit(n);
    for (int i = 0; i < n; i++) {
        Mint add = bit.get(ve[i].first - 1, n);
        bit.upd(ve[i].second, add);
        if (ve[i].first == 1) {
            bit.upd(ve[i].second, 1);
        }
    }
    Mint ret = bit.get(n, n);
    cout << ret << '\n';
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