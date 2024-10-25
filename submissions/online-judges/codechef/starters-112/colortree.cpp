#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> dp(n, vector<ll>(3));
    vector<int> sz(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
        }
        vector<int> odds;
        ll oth = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (sz[c] & 1) {
                odds.push_back(c);
            } else {
                oth = (oth * dp[c][0]) % MOD;
            }
        }
        int osz = odds.size();
        if (sz[v] % 2 == 0) {
            vector<ll> tbl(osz + 1), tmp(osz + 1);
            assert(osz % 2 == 1);
            ll lol = 1;
            for (int i = 0; i < osz; i++) {
                lol = (lol * dp[odds[i]][1]) % MOD;
                tmp[i] = dp[odds[i]][2] * inv(dp[odds[i]][1]) % MOD;
            }
            tbl[0] = 1;
            for (int i = 0; i < osz; i++) {
                for (int j = i + 1; j >= 1; j--) {
                    tbl[j] = (tmp[i] * tbl[j - 1] + tbl[j]) % MOD;
                }
            }
            ll lmao = ((tbl[(osz + 1) / 2] + tbl[(osz - 1) / 2]) * lol) % MOD;
            lmao = (lmao * oth) % MOD;
            dp[v][0] = lmao;
        } else {
            vector<ll> tbl(osz + 1), tmp(osz + 1);
            assert(osz % 2 == 0);
            if (osz == 0) {
                dp[v][1] = dp[v][2] = oth;
            } else {
                ll lol = 1;
                for (int i = 0; i < osz; i++) {
                    lol = (lol * dp[odds[i]][1]) % MOD;
                    tmp[i] = dp[odds[i]][2] * inv(dp[odds[i]][1]) % MOD;
                }
                tbl[0] = 1;
                for (int i = 0; i < osz; i++) {
                    for (int j = i + 1; j >= 1; j--) {
                        tbl[j] = (tmp[i] * tbl[j - 1] + tbl[j]) % MOD;
                    }
                }
                ll lmao = (tbl[osz / 2] * lol) % MOD;
                lmao = (lmao * oth) % MOD;
                ll x1 = (tbl[osz / 2 - 1] * lol) % MOD;
                x1 = (x1 * oth) % MOD;
                ll x2 = (tbl[osz / 2 + 1] * lol) % MOD;
                x2 = (x2 * oth) % MOD;
                dp[v][1] = (lmao + x1) % MOD;
                dp[v][2] = (lmao + x2) % MOD;
            }
        }
    };
    dfs(0, 0);

    // for (int i = 0; i < n; i++) {
    //     cerr << i << ' ' << sz[i] << ' ';
    //     for (int j = 0; j < 3; j++) cerr << dp[i][j] << ' ';
    //     cerr << '\n';
    // }

    ll ans;
    if (sz[0] & 1)
        ans = (dp[0][1] + dp[0][2]) % MOD;
    else
        ans = dp[0][0] % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}