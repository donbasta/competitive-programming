#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tc template <class
tc T1, class T2 > ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
tc T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define PARENS ()
#define EEE(...) EEE1(EEE1(__VA_ARGS__))
#define EEE1(...) EEE2(__VA_ARGS__)
#define EEE2(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EEE(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#ifdef LOCAL
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";
#else
#define debug(...) "itfeelsliketimeispassingsoquickly.thepassageoftimedependsentirelyonwhereyou'restanding.relativitytheory...it'ssoromantic.butit'sjustsotragictoo."
#endif

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> lz;
    Segtree(int n) : lz(4 * n + 5), n(n) {}
    void push(int v) {
        if (!lz[v]) return;
        lz[v << 1] ^= lz[v];
        lz[v << 1 | 1] ^= lz[v];
        lz[v] = 0;
    }
    void flip(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            lz[v] ^= 1;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid) flip(v << 1, s, mid, l, r);
        else if (l >= mid + 1) flip(v << 1 | 1, mid + 1, e, l, r);
        else {
            flip(v << 1, s, mid, l, mid);
            flip(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
    }
    ll get(int v, int s, int e, int idx) {
        if (s == e) {
            return lz[v];
        }
        push(v);
        int mid = (s + e) >> 1;
        if (idx <= mid) return get(v << 1, s, mid, idx);
        return get(v << 1 | 1, mid + 1, e, idx);
    }
    void flip(int l, int r) {
        flip(1, 0, n - 1, l, r);
    }
    int get(int idx) {
        return get(1, 0, n - 1, idx);
    }
};

void el_psy_congroo() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> edge_id;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_id[make_pair(u, v)] = i;
        edge_id[make_pair(v, u)] = i;
    }
    if (k & 1) {
        cout << "No" << '\n';
        return;
    }
    vector<bool> vis(n);
    vector<vector<int>> dfs_tree(n);

    vector<int> cur_cc;
    const function<void(int)> dfs = [&](int v) {
        for (auto c : adj[v]) {
            if (vis[c]) {
                continue;
            }
            cur_cc.push_back(c);
            dfs_tree[v].push_back(c);
            dfs_tree[c].push_back(v);
            vis[c] = true;
            dfs(c);
        }
    };

    vector<int> sz(n), par(n), dep(n);
    const function<void(int, int)> dfs_sz = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : dfs_tree[v]) {
            if (c == p) continue;
            par[c] = v;
            dep[c] = dep[v] + 1;
            dfs_sz(c, v);
            sz[v] += sz[c];
        }
    };

    Segtree sgt(n + 5);
    int T = 0;
    vector<int> id(n), tp(n), id_edge(n, -1);
    const function<void(int, int, int)> dfs_hld = [&](int v, int p, int top) {
        id[v] = T++;
        tp[v] = top;
        int mx_c = -1, mx_sz = -1;
        for (auto c : dfs_tree[v]) {
            if (c == p) continue;
            id_edge[c] = edge_id[make_pair(c, v)];
            if (sz[c] > mx_sz) {
                mx_sz = sz[c];
                mx_c = c;
            }
        }
        if (mx_c == -1) return;
        dfs_hld(mx_c, v, top);
        for (auto c : dfs_tree[v]) {
            if (c == p || c == mx_c) continue;
            dfs_hld(c, v, c);
        }
    };

    const function<void(int, int)> update_path = [&](int x, int y) {
        ll ret = 0;
        while (tp[x] != tp[y]) {
            if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
            sgt.flip(id[tp[x]], id[x]);
            x = par[tp[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        
            cerr << "TES\n";
            cerr << id[x] << ' ' << id[y] << '\n';
        
        sgt.flip(id[x], id[y]);
        return ret;
    };

    int cnt = 0;
    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cur_cc.push_back(i);
        vis[i] = true;
        dfs(i);
        dfs_sz(i, i);
        dfs_hld(i, i, i);
        debug(dfs_tree);

        int sz = cur_cc.size();
        int add = min(k - cnt, 2 * (sz / 2));
        debug(add);
        cnt += add;
        for (int i = 0; i < add; i += 2) {
            debug(cur_cc[i], cur_cc[i + 1]);
            update_path(cur_cc[i], cur_cc[i + 1]);
            for (int i = 1; i < n; i++) {
                cerr << sgt.get(id[n]) << ' ';
            }
            cerr << '\n';
        }
        for (auto c : cur_cc) {
            if (c == i) continue;
            int on = sgt.get(id[c]);
            if (on) {
                indices.push_back(id_edge[c]);
            }
        }
        cur_cc.clear();
    }

    if (cnt < k) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';

    cout << indices.size() << '\n';
    for (auto e : indices) {
        cout << (e + 1) << ' ';
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
