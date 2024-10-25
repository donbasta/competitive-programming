#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    int l = 1, r = n, piv = -1, start = -1;

    const ll MOD[2] = {1000000007, 998244353};
    const ll B[2] = {31, 37};
    ll IB[2];
    for (int i = 0; i < 2; i++) {
        IB[i] = fpow(B[i], MOD[i] - 2, MOD[i]);
    }

    vector<vector<ll>> pre(n, vector<ll>(2));
    vector<vector<ll>> pb(n + 1, vector<ll>(2)), ib(n + 1, vector<ll>(2));
    pb[0][0] = pb[0][1] = 1;
    ib[0][0] = ib[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            pb[i][j] = (pb[i - 1][j] * B[j]) % MOD[j];
            ib[i][j] = (ib[i - 1][j] * IB[j]) % MOD[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int cur_dig = (s[i] - 'A' + 1);
            pre[i][j] = ((1ll * cur_dig * pb[i][j] + ((i > 0) ? pre[i - 1][j] : 0))) % MOD[j];
        }
    }

    auto get_hash = [&](int a, int b) -> ll {
        ll tmp[2];
        for (int i = 0; i < 2; i++) {
            ll hash = (pre[b][i] - ((a > 0) ? pre[a - 1][i] : 0)) % MOD[i];
            hash = (hash * ib[a][i]) % MOD[i];
            if (hash < 0) hash += MOD[i];
            tmp[i] = hash;
        }
        return ((tmp[0] << 32) | tmp[1]);
        // return make_pair(tmp[0], tmp[1]);
    };

    while (l <= r) {
        int mid = (l + r) >> 1;
        unordered_map<ll, vector<int>> mp;
        // map<pair<ll, ll>, vector<int>> mp;
        for (int i = 0; i <= n - mid; i++) {
            mp[get_hash(i, i + mid - 1)].push_back(i);
        }
        int idx = n;
        for (auto c : mp) {
            if (c.second.size() == 1) {
                if (idx > c.second[0]) {
                    idx = c.second[0];
                }
            }
        }
        if (idx < n) {
            piv = mid;
            start = idx;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << s.substr(start, piv) << '\n';
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