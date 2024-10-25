#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, q, start;
    cin >> n >> q >> start;
    --start;

    int ncnt = n + 4 * n + 4 * n;
    vector<vector<pair<int, int>>> adj(ncnt);

    const function<void(int, int, int)> init = [&](int v, int s, int e) {
        if (s == e) {
            adj[v + n].emplace_back(s, 0);
            adj[s].emplace_back(v + n + 4 * n, 0);
            return;
        }
        int mid = (s + e) >> 1;
        init(v << 1, s, mid);
        init(v << 1 | 1, mid + 1, e);
        adj[v + n].emplace_back((v << 1) + n, 0);
        adj[v + n].emplace_back((v << 1 | 1) + n, 0);
        adj[(v << 1) + n + 4 * n].emplace_back(v + n + 4 * n, 0);
        adj[(v << 1 | 1) + n + 4 * n].emplace_back(v + n + 4 * n, 0);
    };
    init(1, 0, n - 1);

    vector<int> ve;
    const function<void(int, int, int, int, int, int)> range_node = [&](int v, int s, int e, int l, int r, int flag) {
        if (s == l && e == r) {
            if (flag == 1) {
                ve.emplace_back(v + n);
            } else {
                ve.emplace_back(v + n + 4 * n);
            }
            return;
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            range_node(v << 1, s, mid, l, r, flag);
        else if (l >= mid + 1)
            range_node(v << 1 | 1, mid + 1, e, l, r, flag);
        else {
            range_node(v << 1, s, mid, l, mid, flag);
            range_node(v << 1 | 1, mid + 1, e, mid + 1, r, flag);
        }
    };

    for (int i = 0; i < q; i++) {
        int t, v, u, l, r, w;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> w;
            --v, --u;
            adj[v].emplace_back(u, w);
        } else if (t == 2) {
            cin >> v >> l >> r >> w;
            --v, --l, --r;
            ve.clear();
            range_node(1, 0, n - 1, l, r, 1);
            for (auto c : ve) {
                adj[v].emplace_back(c, w);
            }
        } else if (t == 3) {
            cin >> v >> l >> r >> w;
            --v, --l, --r;
            ve.clear();
            range_node(1, 0, n - 1, l, r, 2);
            for (auto c : ve) {
                adj[c].emplace_back(v, w);
            }
        }
    }

    vector<ll> dis(ncnt, INF);
    set<pair<ll, int>> se;
    dis[start] = 0;
    se.emplace(0, start);
    while (!se.empty()) {
        auto now = *se.begin();
        se.erase(se.begin());
        for (auto c : adj[now.second]) {
            if (dis[c.first] > now.first + c.second) {
                se.erase(make_pair(dis[c.first], c.first));
                dis[c.first] = now.first + c.second;
                se.emplace(dis[c.first], c.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dis[i] == INF) {
            cout << -1 << ' ';
        } else {
            cout << dis[i] << ' ';
        }
    }
    cout << '\n';
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