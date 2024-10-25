#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

void el_psy_congroo() {
    int n, x, y, k, M;
    cin >> n;
    int ar[n];
    cin >> ar[0] >> x >> y >> k >> M;
    int sum = ar[0];
    for (int i = 1; i < n; i++) {
        ar[i] = (1ll * ar[i - 1] * x + y) % M;
        sum = (sum + ar[i]) % MOD;
    }

    int c[k + 1][k + 1];
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            cerr << c[i][j] << ' ';
        }
        cerr << '\n';
    }

    int pw[k + 1];
    pw[0] = 1;
    for (int i = 1; i <= k; i++) {
        pw[i] = (1ll * pw[i - 1] * (n - 1)) % MOD;
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int tmp = (1ll * c[k][i] * pw[k - i]) % MOD;
        int kur = (i * (i - 1)) / 2;
        kur = (1ll * kur * n) % MOD;
        int mul = (1ll * i * sum - kur) % MOD;
        tmp = (1ll * tmp * mul) % MOD;
        ans = (ans + tmp) % MOD;
    }
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