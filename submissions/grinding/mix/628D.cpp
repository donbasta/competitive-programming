#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int M = 2000;
const ll MOD = 1e9 + 7;
ll pw[M + 5];
ll dp[M + 5][M + 5];
ll dp2[M + 5][M + 5];

void add(ll& x, ll y) { x = (x + y) % MOD; }

bool ok(const string& s, int d, int m) {
    ll tmp = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        int cur = s[i] - '0';
        if (i & 1) {
            if (cur != d) return false;
        } else {
            if (cur == d) return false;
        }
        tmp = (tmp + 1ll * pw[sz - 1 - i] * cur) % m;
    }
    return tmp == 0;
}

ll solve(const string& s, int d, int m) {
    int n = s.length();
    ll ret = 0;
    for (int i = 1; i < n; i++) {
        add(ret, dp[i][0]);
    }
    cerr << s << ' ' << ret << '\n';
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - '0';
        if (i % 2 == 0) {
            int st = ((i == 0) ? 1 : 0);
            for (int j = st; j < cur; j++) {
                if (j == d) continue;
                ll lol = (tmp + 1ll * j * pw[n - 1 - i]) % m;
                if (i < n - 1) {
                    lol = (lol + 1ll * d * pw[n - 2 - i]) % m;
                    cerr << j << ' ' << cur << ' ' << (n - i - 2) << ' ' << lol << ' ' << dp2[n - i - 2][(m - lol) % m] << '\n';
                    ret = (ret + dp2[n - i - 2][(m - lol) % m]) % MOD;
                } else {
                    ret = (ret + (lol == 0)) % MOD;
                }
            }
        } else {
            if (d > cur)
                break;
            else if (d == cur) {
                tmp = (tmp + 1ll * d * pw[n - 1 - i]) % m;
                continue;
            } else {
                ll lol = (tmp + 1ll * d * pw[n - 1 - i]) % m;
                cerr << "masuk " << i << ' ' << ret << '\n';
                ret = (ret + dp2[n - 1 - i][(m - lol) % m]) % MOD;
                cerr << "masuk " << i << ' ' << ret << '\n';
                break;
            }
        }
        cerr << i << ' ' << ret << '\n';
        tmp = (tmp + 1ll * cur * pw[n - 1 - i]) % m;
    }
    if (ok(s, d, m)) ret = (ret + 1) % MOD;
    return ret;
}

void el_psy_congroo() {
    int m, d;
    cin >> m >> d;

    pw[0] = 1;
    for (int i = 1; i <= M; i++) {
        pw[i] = (pw[i - 1] * 10) % MOD;
    }

    dp[0][0] = 1;
    dp2[0][0] = 1;
    if (d != 0) dp2[1][0]++;
    for (int i = 1; i <= 9; i++) {
        if (i == d) continue;
        dp[1][i % m]++;
        dp2[1][i % m]++;
    }
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < m; j++) {
            if (i & 1) {
                add(dp[i + 1][(j * 10 + d) % m], dp[i][j]);
                add(dp2[i + 1][(j * 10 + d) % m], dp2[i][j]);
            } else {
                for (int k = 0; k <= 9; k++) {
                    if (k == d) continue;
                    add(dp[i + 1][(j * 10 + k) % m], dp[i][j]);
                    add(dp2[i + 1][(j * 10 + k) % m], dp2[i][j]);
                }
            }
        }
    }

    string a, b;
    cin >> a >> b;

    // brute(a, b, d, m);

    ll B = solve(b, d, m);
    ll A = solve(a, d, m);
    cerr << B << ' ' << A << '\n';
    ll ans = B - A;
    if (ok(a, d, m)) ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}