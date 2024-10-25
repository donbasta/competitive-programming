#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;
const int N = 250000;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    vector<int> fc(N + 1), ifc(N + 1);
    fc[0] = 1;
    for (int i = 1; i <= N; i++) fc[i] = (1ll * fc[i - 1] * i) % MOD;
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;

    auto comb = [&](int a, int b) -> int {
        if (a < 0 || b < 0 || a < b) return 0;
        int ret = (1ll * fc[a] * ifc[b]) % MOD;
        ret = (1ll * ret * ifc[a - b]) % MOD;
        return ret;
    };

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(3);
    for (auto e : s) {
        cnt[e - 'A']++;
    }

    int ans = 0;
    for (int x = 0; x <= min(k, cnt[0]); x++) {
        for (int y = 0; y <= min(k, cnt[1]); y++) {
            for (int z = 0; z <= min(k, cnt[2]); z++) {
                for (int x1 = 0; x1 <= min(k, cnt[0] - x); x1++) {
                    int y1 = x + x1 - z;
                    int z1 = y + y1 - x;
                    if (y1 < 0 || z1 < 0 || y1 + y > cnt[1] || z + z1 > cnt[2]) continue;
                    // filter number of move
                    int move = z + z1 + max(x, y1);
                    if (move > k) continue;
                    int pa = (1ll * comb(cnt[0], x) * comb(cnt[0] - x, x1)) % MOD;
                    int pb = (1ll * comb(cnt[1], y) * comb(cnt[1] - y, y1)) % MOD;
                    int pc = (1ll * comb(cnt[2], z) * comb(cnt[2] - z, z1)) % MOD;
                    int tmp = (1ll * pa * pb) % MOD;
                    tmp = (1ll * tmp * pc) % MOD;
                    ans = (1ll * ans + tmp) % MOD;
                }
            }
        }
    }
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