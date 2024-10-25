#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<ll> F(n + 1);
    vector<vector<ll>> G(n + 1, vector<ll>(k + 1));
    vector<vector<ll>> PG(n + 1, vector<ll>(k + 1));
    G[1][1] = k;
    for (int j = 1; j <= k; j++) {
        PG[1][j] = PG[1][j - 1] + G[1][j];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i, k - 1); j++) {
            G[i][j] = 1ll * (k - j + 1) * G[i - 1][j - 1] % MOD;
            G[i][j] = (G[i][j] + PG[i - 1][k - 1] - PG[i - 1][j - 1]) % MOD;
        }
        for (int j = 1; j <= k; j++) {
            PG[i][j] = PG[i][j - 1] + G[i][j];
        }
    }

    vector<ll> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] * k) % MOD;
    }

    for (int i = k; i <= n; i++) {
        for (int j = 1; j <= i - k + 1; j++) {
            F[i] = (F[i] + 1ll * G[j + k - 2][k - 1] * (F[i - k + 1 - j] + pw[i - k + 1 - j])) % MOD;
        }
    }

    ll ans = F[n] % MOD;
    if (ans < 0) ans += MOD;
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