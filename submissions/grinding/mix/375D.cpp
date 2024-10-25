#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 2e9;
const int M = 1e5;
const int B = 300;

struct Query {
    int l, r, idx, k;
    bool operator<(Query other) const {
        return make_pair(l / B, r) <
               make_pair(other.l / B, other.r);
    }
};

struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) : n(n + 5), bit(n + 5) {}
    void upd(int x, int val) {
        x++;
        while (x <= n) {
            bit[x] += val, x += x & -x;
        }
    }
    int get(int x) {
        x++;
        int ret = 0;
        while (x) {
            ret += bit[x], x -= x & -x;
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    vector<int> tin(n), sz(n), eul;
    int T = 0;
    const function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = T++;
        eul.push_back(col[v]);
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
        }
    };
    dfs(0, 0);

    vector<int> ret(m);
    vector<Query> que;
    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        --v;
        que.emplace_back(Query{tin[v], tin[v] + sz[v] - 1, i, k});
    }
    sort(que.begin(), que.end());
    int cnt = 0;
    vector<int> cnt_col(M + 1);
    BIT ft(M);
    ft.upd(0, M);
    int cl = 0, cr = -1;
    for (auto q : que) {
        while (cl > q.l) {
            cl--;
            ft.upd(cnt_col[eul[cl]], -1);
            cnt_col[eul[cl]]++;
            ft.upd(cnt_col[eul[cl]], 1);
        }
        while (cr < q.r) {
            cr++;
            ft.upd(cnt_col[eul[cr]], -1);
            cnt_col[eul[cr]]++;
            ft.upd(cnt_col[eul[cr]], 1);
        }
        while (cl < q.l) {
            ft.upd(cnt_col[eul[cl]], -1);
            cnt_col[eul[cl]]--;
            ft.upd(cnt_col[eul[cl]], 1);
            cl++;
        }
        while (cr > q.r) {
            ft.upd(cnt_col[eul[cr]], -1);
            cnt_col[eul[cr]]--;
            ft.upd(cnt_col[eul[cr]], 1);
            cr--;
        }
        ret[q.idx] = ft.get(M) - ft.get(q.k - 1);
    }
    for (int i = 0; i < m; i++) {
        cout << ret[i] << '\n';
    }
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