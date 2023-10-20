#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

const vector<vector<int>> ADJ = {
    {6, 9},
    {8, 10, 7},
    {4, 9, 11},
    {5, 10},
    {2, 10, 13},
    {3, 11, 14, 12},
    {0, 8, 13, 15},
    {1, 9, 14},
    {1, 6, 14},
    {0, 2, 7, 15},
    {3, 1, 4, 12},
    {2, 5, 13},
    {5, 10},
    {4, 6, 11},
    {5, 7, 8},
    {6, 9},
};

void solve() {
    vector<ll> m(16);
    for (int i = 0; i < 16; i++) {
        cin >> m[i];
    }

    vector<vector<ll>> dp((1 << 16), vector<ll>(16, -1));
    vector<vector<pair<ll, ll>>> lmao((1 << 16), vector<pair<ll, ll>>(16, make_pair(0, -1)));
    const function<ll(int, int)> DP = [&](int mask, int v) -> ll {
        if (dp[mask][v] != -1) return dp[mask][v];
        ll tmp = 0;
        int nx = -1;
        for (auto i : ADJ[v]) {
            if ((mask >> i) & 1) continue;
            ll cur = 1ll * m[v] * m[i] + DP(mask ^ (1 << i), i);
            if (cur > tmp) {
                nx = i;
                tmp = cur;
            } else if (cur == tmp) {
                if (i < nx) {
                    nx = i;
                }
            }
        }
        if (nx == -1) {
            lmao[mask][v] = make_pair(0, -1);
            return dp[mask][v] = 0;
        }
        lmao[mask][v] = make_pair(mask ^ (1 << nx), nx);
        return dp[mask][v] = tmp;
    };

    ll ans = 0;
    for (int i = 0; i < 16; i++) {
        ans = max(ans, DP(1 << i, i));
    }
    for (int i = 0; i < 16; i++) {
        if (DP(1 << i, i) == ans) {
            vector<int> ret;
            int cur = i;
            int mask = (1 << i);
            cout << ans << '\n';
            while (cur != -1) {
                ret.push_back(cur);
                auto t = lmao[mask][cur];
                mask = t.first;
                cur = t.second;
            }
            for (auto e : ret) {
                cout << (e + 1) << ' ';
            }
            cout << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}