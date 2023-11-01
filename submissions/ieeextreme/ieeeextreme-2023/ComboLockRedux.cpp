#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e9 + 9;

struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

void el_psy_congroo() {
    int n, t, h, a, b, q;
    cin >> n >> t >> h >> a >> b >> q;

    vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 10;
    }

    DSU dsu(pw[n]);

    vector<bool> allowed(pw[n]);
    allowed[0] = allowed[t] = true;
    if (t == 0) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        int cur = (0 / pw[i]) % 10;
        int nx = (cur + 1) % 10;
        int prv = (cur + 9) % 10;
        int hh_nx = 0 - cur * pw[i] + nx * pw[i];
        int hh_prv = 0 - cur * pw[i] + prv * pw[i];
        if (hh_nx == t || hh_prv == t) {
            cout << 1 << ' ' << 1 << '\n';
            return;
        }
    }

    const int M = 1e7 + 1;
    vector<bool> vis(M);
    bool can = false;
    while (true) {
        if (vis[h]) {
            break;
        }
        vis[h] = true;

        int hh = h % pw[n];
        // if (hh != 0 && hh != t && allowed[hh]) {
        //     break;
        // }

        allowed[hh] = true;
        for (int i = 0; i < n; i++) {
            int cur = (hh / pw[i]) % 10;
            int nx = (cur + 1) % 10;
            int prv = (cur + 9) % 10;
            int hh_nx = hh - cur * pw[i] + nx * pw[i];
            int hh_prv = hh - cur * pw[i] + prv * pw[i];
            if (allowed[hh_nx]) {
                dsu.merge(hh_nx, hh);
            }
            if (allowed[hh_prv]) {
                dsu.merge(hh_prv, hh);
            }
            // if (hh_nx == t || hh_nx == 0) {
            //     allowed[hh_nx] = true;
            //     dsu.merge(hh_nx, hh);
            // }
            // if (hh_prv == t || hh_prv == 0) {
            //     allowed[hh_prv] = true;
            //     dsu.merge(hh_prv, hh);
            // }
        }

        // cerr << h << ' ' << hh << ' ' << dsu.fpar(t) << ' ' << dsu.fpar(0) << '\n';

        if (dsu.fpar(t) == dsu.fpar(0)) {
            can = true;
            break;
        }
        h = (1ll * a * h + b) % q;
    }

    if (!can) {
        cout << -1 << '\n';
        return;
    }

    vector<bool> visited(pw[n]);
    vector<int> dis(pw[n], INF);
    vector<int> dp(pw[n], 0), in(pw[n], 0);
    vector<vector<int>> from(pw[n]);

    queue<int> Q;
    Q.emplace(0);
    visited[0] = true;
    dis[0] = 0;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (int i = 0; i < n; i++) {
            int cur = (now / pw[i]) % 10;
            int nx = (cur + 1) % 10;
            int prv = (cur + 9) % 10;
            int hh_nx = now - cur * pw[i] + nx * pw[i];
            int hh_prv = now - cur * pw[i] + prv * pw[i];
            // cerr << now << ' ' << hh_nx << ' ' << hh_prv << '\n';
            if (allowed[hh_nx]) {
                if (!visited[hh_nx]) {
                    dis[hh_nx] = dis[now] + 1;
                    visited[hh_nx] = true;
                    from[now].push_back(hh_nx);
                    in[hh_nx]++;
                    Q.emplace(hh_nx);
                } else {
                    if (dis[hh_nx] == dis[now] + 1) {
                        from[now].push_back(hh_nx);
                        in[hh_nx]++;
                    }
                }
            }
            if (allowed[hh_prv]) {
                if (!visited[hh_prv]) {
                    dis[hh_prv] = dis[now] + 1;
                    visited[hh_prv] = true;
                    from[now].push_back(hh_prv);
                    in[hh_prv]++;
                    Q.emplace(hh_prv);
                } else {
                    if (dis[hh_prv] == dis[now] + 1) {
                        from[now].push_back(hh_prv);
                        in[hh_prv]++;
                    }
                }
            }
        }
    }

    assert(Q.empty());
    Q.emplace(0);
    dp[0] = 1;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : from[now]) {
            dp[c] = (1ll * dp[c] + dp[now]) % MOD;
            --in[c];
            if (in[c] == 0) {
                Q.emplace(c);
            }
        }
    }

    cout << dis[t] << ' ' << dp[t] << '\n';
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