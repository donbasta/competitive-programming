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

    mint dp[n][m][c + 1][c + 1][c + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x <= c; x++) {
                for (int y = 0; y <= c; y++) {
                    for (int z = 0; z <= c; z++) {
                        dp[i][j][x][y][z] = 0;
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (ve[i][j]) {
                for (int kk = 1; kk <= c; kk++) {
                    for (int k = 0; k <= c; k++) {
                        for (int l = 0; l <= c; l++) {
                            for (int x = 0; x <= c; x++) {
                                for (int y = 0; y <= c; y++) {
                                    int cek = (x == kk) + (y == kk) + (k == kk);
                                    if (cek >= 2) continue;
                                    dp[i][j][kk][k][l] += dp[i][j - 1][x][y][k];
                                }
                            }
                        }
                    }
                }
            } else {
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= c; l++) {
                        for (int x = 0; x <= c; x++) {
                            for (int y = 0; y <= c; y++) {
                                dp[i][j][0][k][l] += dp[i][j - 1][x][y][k];
                            }
                        }
                    }
                }
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