#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct mint {
    const int MOD = 1e9 + 7;
    int x;

    mint(int _x) : x((_x % MOD + MOD) % MOD) {}
    mint(long long _x) : x((_x % MOD + MOD) % MOD) {}

    mint() : x(0) {}

    mint &operator=(const mint &rhs) {
        x = rhs.x;
        return *this;
    }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = mint(1);
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator+=(const mint &rhs) {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }

    mint &operator-=(const mint &rhs) {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
        return *this;
    }

    mint &operator*=(const mint &rhs) {
        unsigned long long z = x;
        z *= rhs.x;
        x = (unsigned int)(z % MOD);
        return *this;
    }

    mint &operator/=(const mint &rhs) {
        return *this = *this * rhs.inv();
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {
        return mint(lhs) /= rhs;
    }

    friend ostream& operator<<(ostream &os, const mint &m) {
        return os << m.x;
    }
};

const int N = 2e6;
mint fc[N + 5], ifc[N + 5];

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = fc[i - 1] * i;
    }
    ifc[N] = fc[N].inv();
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1);
    }
}

mint C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    mint ans = fc[a] * ifc[a - b] * ifc[b];
    return ans;
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> ve;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int pw = 0;
            while (x % i == 0) {
                pw++, x /= i;
            }
            ve.emplace_back(i, pw);
        }
    }
    if (x > 1) {
        ve.emplace_back(x, 1);
    }
    return ve;
}

void solve() {
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> p = factorize(x);
    mint ans = 1;
    for (auto e : p) {
        int pr = e.first, pw = e.second;
        ans *= C(pw + y - 1, y - 1);
    }
    ans *= mint(2).pow(y - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;

    init_fac();
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}