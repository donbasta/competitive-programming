#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const int M = 2000; 
ll m, d;
string a, b;

ll pw[M + 10];
ll dp[M + 10][M + 10];
ll DP[M + 10][M + 10];

inline ll md (ll x, ll y) { x %= y; if (x < 0) x += y; return x; }
inline void add (ll& x, ll y, ll z) { x = (x + y) % z; }
inline void fill_pw () { for (int i = 0; i < M; i++) { pw[i] = (pw[i - 1] * 10) % m; } }

void fill_dp () {
    dp[0][0] = 1;
    for (int i = 0; i <= 9; i++) { dp[1][(i % m)]++; }
    for (int i = 1; i <= 9; i++) { dp[2][(10 * i + d) % m]++; }
    for (ll i = 3; i <= M; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll k = 0; k <= 9; k++) {
                add(dp[i][j], dp[i - 2][md(j - k * pw[i - 1] - d * pw[i - 2], m)], mod);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        DP[1][i] = dp[1][i], DP[2][i] = dp[2][i];
        for (int j = 3; j <= M; j++) {
            DP[j][i] = (dp[j][i] - dp[j - 2][md(i - d * pw[j - 2], m)]);
            DP[j][i] = md (DP[j][i], mod);
        }
    }
}

bool is_magic (string s) {
    int n = (int)s.length();
    bool ok = 1;
    ll cek;
    for (int i = 0; i < n; i++) {
        ll dig = s[i] - '0';
        if (i & 1) ok &= (dig == d);
        cek = (cek + dig * pw[n - 1 - i]) % m;
    }
    return ok && !cek;
} 

ll get (string s) {
    ll ret = 0;
    ll cur = 0;
    int len = (int)s.length();
    for (int i = 1; i < len; i++) {
        add(ret, DP[i][0], mod);
    }
    for (ll i = len - 1; i >= 0; i -= 2) {
        int dig = s[len - 1 - i] - '0';
        for (ll j = 1; j < dig; j++) {
            if (i > 0)
                add (ret, DP[i - 1][md(m - cur - j * pw[i] - d * pw[i - 1], m)], mod);
            else
                add (ret, DP[0][md(m - j * pw[i], m)], mod);
        }
        if (i > 0) {
            int dig_next = s[len - i] - '0';
            if (dig_next > d) break;
            add(cur, dig * pw[i] + d * pw[i - 1], m);
        }
    }
    return ret;
}

void solve() {
    cin >> m >> d;
    fill_pw ();
    fill_dp ();
    cin >> a >> b;
    ll ans = get (a) - get (b) + is_magic (b);
    ans = md (ans, mod);
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