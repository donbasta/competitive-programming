#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e3;

int n;
vector<pair<int, int>> li[N * N + 5];
ll dp[N + 5][N + 5];
ll ans[N + 5][N + 5];
ll fc[2 * N + 5], ifc[2 * N + 5];
string s[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

inline ll inv(ll a) { return fpow(a, MOD - 2); }

void init() {
    fc[0] = 1;
    for (int i = 1; i <= 2 * N; i++) { fc[i] = fc[i - 1] * i % MOD; }
    ifc[2 * N] = inv(fc[2 * N]);
    for (int i = 2 * N - 1; i >= 0; i--) { ifc[i] = ifc[i + 1] * (i + 1) % MOD; }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a] * ifc[b] % MOD;
    ret = ret * ifc[a - b] % MOD;
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll cek = 0;
            if (i > 0) cek = max(cek, dp[i - 1][j]);
            if (j > 0) cek = max(cek, dp[i][j - 1]);
            dp[i][j] = (s[i][j] == '1') + cek;
            if (dp[i][j] < 1 || (s[i][j] == '1')) {
                li[dp[i][j]].emplace_back(i, j); 
            }
        }
    }
    for (auto t : li[0]) {
        int a = t.first, b = t.second;
        ans[a][b] = C(a + b, a);
    }
    for (auto t : li[1]) {
        int a = t.first, b = t.second;
        ans[a][b] = C(a + b, a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mx = dp[i][j];
            if (mx == 0) continue;
            int cek = (s[i][j] == '1' ? mx - 1 : mx);
            for (auto t : li[cek]) {
                int a = t.first, b = t.second;
                if (a <= i && b <= j && !((a == i) && (b == j)) && (s[a][b] == '1')) {
                    ans[i][j] = (ans[i][j] + ans[a][b] * C(i + j - a - b, i - a)) % MOD;
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << ' ' << ans[n - 1][n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}