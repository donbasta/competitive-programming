#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dp0(n, -INF), dp1(n, -INF), dp2(n, -INF), dp3(n, -INF);
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        vector<ll> tmp;
        dp0[v] = val[v];
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            tmp.push_back(max({dp0[c], dp1[c] - val[c], dp2[c] + val[c], dp3[c]}));
        }
        sort(tmp.begin(), tmp.end(), greater<>());
        if (!tmp.empty()) dp1[v] = val[v] + tmp[0];
        if (tmp.size() >= 2) dp2[v] = tmp[0] + tmp[1];
        if (tmp.size() >= 3) {
            ll lmao = 0;
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] <= 0 && i >= 3) break;
                lmao += tmp[i];
            }
            dp3[v] = val[v] + lmao;
        }
    };

    dfs(0, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, max({dp0[i], dp1[i], dp2[i], dp3[i]}));
    }
    cout << ans << '\n';
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