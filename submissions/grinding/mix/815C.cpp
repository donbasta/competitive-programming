#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, b;
    cin >> n >> b;
    vector<ll> c(n), d(n), x(n), cd(n);
    vector<vector<int>> chd(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
        cd[i] = c[i] - d[i];
        if (i > 0) {
            cin >> x[i];
            --x[i];
            chd[x[i]].push_back(i);
        }
    }
    vector<ll> dp(n);
    dp[0] = cd[0];
    vector<bool> used(n);
    vector<pair<ll, ll>> ve;
    for (int i = 0; i < n; i++) {
        ve.emplace_back(c[i], i);
    }
    sort(ve.begin(), ve.end());
    used[0] = true;
    ll ans = 0;
    const function<void(int, int)> dfs = [&](int v, int cnt) {
        ll sisa = b - dp[v];
        ll tmp = cnt;
        if (sisa >= 0) {
            for (int i = 0; i < n; i++) {
                if (used[ve[i].second]) continue;
                if (ve[i].first > sisa) break;
                sisa -= ve[i].first;
                tmp++;
            }
            ans = max(ans, tmp);
        }
        for (auto c : chd[v]) {
            dp[c] = dp[v] + cd[c];
            used[c] = true;
            dfs(c, cnt + 1);
            used[c] = false;
        }
    };
    dfs(0, 1);
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