#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const int INF = 2e9;
const int N = 1e6 + 3;

pair<int, int> pts[N];
vector<int> adj[N], g[N];
vector<bool> used[N];
ll area[N], dp[N][2];
// map<pair<int, int>, int> mp;  // shared edge
// unordered_map<int, int> se[N];
vector<int> mark[N];
// unordered_map<int, int> f[N];

void dfs(int v, int p) {
    dp[v][1] = area[v];
    dp[v][0] = 0;
    for (auto c : g[v]) {
        if (c == p) continue;
        dfs(c, v);
        dp[v][0] += max(dp[c][1], dp[c][0]);
        dp[v][1] += dp[c][0];
    }
}

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    assert(m <= n - 3);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = make_pair(x, y);
    }
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int nx = (i + 1) % n;
        adj[i].push_back(nx);
        adj[nx].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        used[i].resize(adj[i].size());
        mark[i].assign(adj[i].size(), -1);
        // for (int j = 0; j < adj[i].size(); j++) {
        //     f[adj[i][j]][i] = j;
        // }
    }
    int cnt = -1;

    const function<ll(int, int, int)> get_area_triangle = [&](int p, int q, int r) -> ll {
        int x1 = pts[p].first, y1 = pts[p].second;
        int x2 = pts[q].first, y2 = pts[q].second;
        int x3 = pts[r].first, y3 = pts[r].second;
        return abs(1ll * x1 * y2 + 1ll * x2 * y3 + 1ll * x3 * y1 - 1ll * x2 * y1 - 1ll * x3 * y2 - 1ll * x1 * y3);
    };

    int reg[n];
    int idxx[n], idyy[n];
    const function<ll(int)> get_area = [&](int sz) -> ll {
        assert(sz >= 3);
        ll A = 0;
        for (int i = 1; i <= sz - 2; i++) {
            A += get_area_triangle(reg[0], reg[i], reg[i + 1]);
        }
        return A;
    };

    for (int i = 0; i < n; i++) {
        for (int id = 0; id < (int)adj[i].size(); id++) {
            if (used[i][id]) continue;
            int buf = 0;
            int p = i;
            int go = id;
            while (!used[p][go]) {
                // reg.push_back(p);
                used[p][go] = true;
                int new_p = adj[p][go];
                int new_go = lower_bound(adj[new_p].begin(), adj[new_p].end(), p) - adj[new_p].begin();
                reg[buf] = p;
                idxx[buf] = go;
                idyy[buf] = new_go;
                buf++;
                new_go = (new_go + 1) % adj[new_p].size();
                p = new_p;
                go = new_go;
            }
            if (cnt == -1) {
                cnt++;
                continue;
            }
            // int sz = reg.size();
            int sz = buf;
            for (int j = 0; j < sz; j++) {
                int x = reg[j];
                int y = reg[(j + 1) % sz];
                // if (x > y) {
                //     swap(x, y);
                // }
                if (mark[x][idxx[j]] != -1 || mark[y][idyy[j]] != -1) {
                    int oth = mark[x][idxx[j]];
                    g[cnt].push_back(oth);
                    g[oth].push_back(cnt);
                } else {
                    mark[x][idxx[j]] = mark[y][idyy[j]] = cnt;
                }

                // if (se[x].count(y)) {
                //     int oth = se[x][y];
                //     g[cnt].push_back(oth);
                //     g[oth].push_back(cnt);
                // } else {
                //     se[x][y] = cnt;
                // }

                // pair<int, int> z = make_pair(x, y);
                // if (mp.find(z) != mp.end()) {
                //     int oth = mp[z];
                //     g[cnt].push_back(oth);
                //     g[oth].push_back(cnt);
                // } else {
                //     mp[z] = cnt;
                // }
            }
            area[cnt] = get_area(buf);
            cnt++;
        }
    }

    dfs(0, 0);
    ll ans = max(dp[0][0], dp[0][1]);
    // cout << 0 << '\n';
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