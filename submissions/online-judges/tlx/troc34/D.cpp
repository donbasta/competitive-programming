#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

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
    int k;
    cin >> k;
    vector<ll> lan, cnt(n);
    for (int i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        --b;
        lan.push_back(a);
        cnt[b]++;
    }
    sort(lan.begin(), lan.end());
    ll ans = 0;
    for (int i = 0; i < (k / 2); i++) {
        ans -= lan[i];
    }
    for (int i = k - 1; i >= k - (k / 2); i--) {
        ans += lan[i];
    }

    vector<ll> nd(n), dis(n);
    vector<ll> dp(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        nd[v] = cnt[v];
        for (auto c : adj[v]) {
            if (c == p) continue;
            dis[c] = dis[v] + 1;
            dfs(c, v);
            nd[v] += nd[c];
        }
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        dp[0] += 1ll * cnt[i] * dis[i];
    }
    const function<void(int, int)> dfs_reroot = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            dp[c] = dp[v] - nd[c];
            dp[c] = dp[c] + (k - nd[c]);
            dfs_reroot(c, v);
        }
    };
    dfs_reroot(0, 0);
    ll tam = INF;
    for (int i = 0; i < n; i++) {
        tam = min(tam, dp[i]);
    }
    ans += tam;
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