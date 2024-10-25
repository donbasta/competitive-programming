#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;
const int N = 1e5;

ll fc[N + 5], ifc[N + 5];
ll dp[26][N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (fc[a] * ifc[b]) % MOD * ifc[a - b] % MOD;
}

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    ll tot = fc[n];
    for (int i = 0; i < 26; i++) {
        tot = (tot * ifc[cnt[i]]) % MOD;
    }
    int idx = 0;
    int cur_len = 0;
    while (cnt[idx] == 0) idx++;
    dp[idx][cnt[idx] - 1] = 1;
    cur_len = cnt[idx];
    for (int i = idx + 1; i < 26; i++) {
        cur_len += cnt[i];
        for (int j = 0; j < cur_len; j++) {
            dp[i][j];
        }
    }
    ll ret = (dp[25][0] * fpow(tot, MOD - 2)) % MOD;
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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