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

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<bool>> ve(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            ve[i][j] = (c == '.');
        }
    }

    vector<vector<vector<mint>>> dp(m, vector<vector<mint>>(c + 1, vector<mint>(c + 1)));
    vector<vector<mint>> p1(m, vector<mint>(c + 1)), p2(m, vector<mint>(c + 1));
    vector<mint> pre(m);
    {
        if (ve[0][0] && ve[1][0]) {
            for (int j = 1; j <= c; j++) {
                for (int k = 1; k <= c; k++) {
                    dp[0][j][k] = 1;
                }
            }
        } else if (ve[0][0]) {
            for (int j = 1; j <= c; j++) {
                dp[0][j][0] = 1;
            }
        } else if (ve[1][0]) {
            for (int j = 1; j <= c; j++) {
                dp[0][0][j] = 1;
            }
        } else {
            dp[0][0][0] = 1;
        }
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k <= c; k++) {
                pre[0] += dp[0][j][k];
                p1[0][j] += dp[0][j][k];
                p2[0][k] += dp[0][j][k];
            }
        }
    }

    mint ans = 1;
    for (int i = 1; i < m; i++) {
        if (ve[0][i] && ve[1][i]) {
            for (int j = 1; j <= c; j++) {
                for (int k = 1; k <= c; k++) {
                    if (j == k) {
                        mint tmp = pre[i - 1] - p1[i - 1][j] - p2[i - 1][j] + dp[i - 1][j][j];
                        dp[i][j][k] = tmp;
                    } else {
                        dp[i][j][k] = pre[i - 1] - dp[i - 1][j][j] - dp[i - 1][k][k];
                    }
                }
            }
        } else if (ve[0][i]) {
            for (int j = 1; j <= c; j++) {
                dp[i][j][0] = pre[i - 1] - dp[i - 1][j][j];
            }
        } else if (ve[1][i]) {
            for (int j = 1; j <= c; j++) {
                dp[i][0][j] = pre[i - 1] - dp[i - 1][j][j];
            }
        } else {
            ans *= pre[i - 1];
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k <= c; k++) {
                pre[i] += dp[i][j][k];
                p1[i][j] += dp[i][j][k];
                p2[i][k] += dp[i][j][k];
            }
        }
    }
    ans *= pre[m - 1];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}