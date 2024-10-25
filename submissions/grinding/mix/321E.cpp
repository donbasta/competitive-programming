#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> u(n, vector<int>(n)), pf(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> u[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pf[i][j] = u[i][j];
            if (i) pf[i][j] += pf[i - 1][j];
            if (j) pf[i][j] += pf[i][j - 1];
            if ((i > 0) && (j > 0)) pf[i][j] -= pf[i - 1][j - 1];
        }
    }
    auto cost = [&](int a, int b) -> int {
        int ret = pf[b][b];
        if (a) {
            ret = (ret - pf[a - 1][b] - pf[b][a - 1] + pf[a - 1][a - 1]);
        }
        return ret / 2;
    };
    vector<ll> dp(n), ndp(n);

    const function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ll, int> best = make_pair(INF, -1);
        for (int i = optl; i <= min(mid, optr); i++) {
            best = min(best, make_pair((i ? dp[i - 1] : 0ll) + cost(i, mid), i));
        }
        ndp[mid] = best.first;
        int opt = best.second;
        solve(l, mid - 1, optl, opt);
        solve(mid + 1, r, opt, optr);
    };

    for (int i = 0; i < n; i++) {
        dp[i] = cost(0, i);
    }
    for (int i = 1; i < k; i++) {
        solve(0, n - 1, 0, n - 1);
        dp.swap(ndp);
    }
    cout << dp[n - 1] << '\n';
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