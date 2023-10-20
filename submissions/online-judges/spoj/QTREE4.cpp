#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 1e5;
const int B = 18;

struct Segtree {
    vector<int> tree;
    void resize(int n) { tree.resize(4 * n + 5); }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
} sgt;

int n;
vector<int> adj[N + 5];
bool processed[N + 5], col[N + 5];
int sz[N + 5], par[N + 5], dep[N + 5];
multiset<int> ms[N + 5];
int up[N + 5][B];
map<pair<int, int>, int> w;
int gre[N + 5];
multiset<int> se;
unordered_map<int, multiset<int>> msc[N + 5];
unordered_map<int, int> mxc[N + 5];

int timer = 0;
int tin[N + 5], tout[N + 5];
void dfs_lca(int v, int p) {
    tin[v] = timer++;
    up[v][0] = p;
    for (int i = 1; i < B; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto c : adj[v]) {
        if (c == p) continue;
        dep[c] = dep[v] + w[make_pair(min(v, c), max(v, c))];
        dfs_lca(c, v);
    }
    tout[v] = timer++;
}

bool is_ancestor(int a, int b) {
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b) {
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i = B - 1; i >= 0; i--) {
        if (!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

void dfs_size(int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
}

int get_centroid(int v, int p, int tree_size) {
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        if (sz[c] > (tree_size / 2)) return get_centroid(c, v, tree_size);
    }
    return v;
}

void centroid_decomposition(int v, int p) {
    dfs_size(v, p);
    int ctr = get_centroid(v, p, sz[v]);
    par[ctr] = (p == -1 ? ctr : p);
    processed[ctr] = true;
    for (auto c : adj[ctr]) {
        if (processed[c]) continue;
        centroid_decomposition(c, ctr);
    }
}

void upd(int x) {
    int tx = x;
    col[x] ^= 1;
    if (col[x])
        ms[x].insert(0);
    else if (!col[x])
        ms[x].erase(ms[x].find(0));
    int nw = -INF;
    if (col[x]) {
        nw = max(nw, *ms[x].rbegin());
    } else {
        if (ms[x].size() >= 2) {
            nw = max(nw, *ms[x].rbegin() + *(++ms[x].rbegin()));
        }
    }
    if (gre[x] != nw) {
        sgt.upd(1, 0, n - 1, tx, nw);
        gre[x] = nw;
    }
    if (x == par[x]) return;
    int prv = x;
    tx = par[x];
    while (true) {
        if (!col[x]) {
            msc[tx][prv].erase(msc[tx][prv].find(dis(x, tx)));
        } else {
            msc[tx][prv].insert(dis(x, tx));
        }
        if (msc[tx][prv].empty()) {
            ms[tx].erase(ms[tx].find(mxc[tx][prv]));
            mxc[tx][prv] = -INF;
        } else {
            // cerr << "masuk when updating " << x << '\n';
            if (mxc[tx][prv] != *msc[tx][prv].rbegin()) {
                if (mxc[tx][prv] != -INF && !ms[tx].empty()) {
                    ms[tx].erase(ms[tx].find(mxc[tx][prv]));
                }
                mxc[tx][prv] = *msc[tx][prv].rbegin();
                ms[tx].insert(mxc[tx][prv]);
            }
        }
        int nw = -INF;
        // cerr << "LMAO " << x << " " << tx << " " << ms[tx].size() << '\n';
        if (!ms[tx].empty()) {
            if (col[tx]) {
                nw = max(nw, *ms[tx].rbegin());
            }
            if (ms[tx].size() >= 2) {
                // cerr << "KONT" << '\n';
                nw = max(nw, *ms[tx].rbegin() + *(++ms[tx].rbegin()));
            }
        }
        // cerr << "TX: " << tx << " NW: " << nw << '\n';
        if (gre[tx] != nw) {
            sgt.upd(1, 0, n - 1, tx, nw);
            gre[tx] = nw;
        }
        if (tx == par[tx]) break;
        prv = tx;
        tx = par[tx];
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (a > b) swap(a, b);
        w[make_pair(a, b)] = c;
    }
    dfs_lca(0, 0);
    centroid_decomposition(0, -1);

    sgt.resize(n);
    for (int i = 0; i < n; i++) {
        gre[i] = -INF;
        sgt.upd(1, 0, n - 1, i, -INF);
    }
    for (int i = 0; i < n; i++) {
        if (i == par[i]) continue;
        mxc[par[i]][i] = -INF;
    }
    for (int i = 0; i < n; i++) {
        upd(i);
    }

    // for (int i = 0; i < n; i++) {
    //     for (auto e : ms[i]) {
    //         cerr << e << ' ';
    //     }
    //     cerr << '\n';
    // }

    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'C') {
            int x;
            cin >> x;
            --x;
            upd(x);
            // for (int i = 0; i < n; i++) {
            //     cerr << "(" << i << ' ' << sgt.get(1, 0, n - 1, i, i) << ")" << ' ';
            // }
            // cerr << '\n';
        } else if (type == 'A') {
            int x = sgt.tree[1];
            if (x == -INF) {
                cout << "They have disappeared." << '\n';
            } else {
                cout << (x) << '\n';
            }
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