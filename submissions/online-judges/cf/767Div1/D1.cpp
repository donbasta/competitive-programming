
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
    int n, m, k;
    cin >> n >> m >> k;
    ll i2 = inv(2);
    vector<vector<ll>> F(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        F[i][i] = i;
        for (int j = 1; j <= i - 1; j++) {
            F[i][j] = ((F[i - 1][j - 1] + F[i - 1][j]) * i2) % MOD;
        }
    }
    ll ret = F[n][m];
    ret = (ret * k) % MOD;
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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