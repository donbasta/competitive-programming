#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18 + 69;

struct Line {
    mutable ll k, m, p, idx;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {  // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m, ll idx) {
        auto z = insert({k, m, 0, idx}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    pair<ll, ll> query(ll x) {
        if (empty()) {
            return make_pair(-1, -1);
        }
        auto l = *lower_bound(x);
        return make_pair(l.k * x + l.m, l.idx);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int, int>, ll> weight;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[make_pair(u, v)] = w;
        weight[make_pair(v, u)] = w;
    }

    vector<ll> longest(n), par(n, -1), simpan(n), puncak(n);
    ll diameter_ori = 0;
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dfs(c, v);
        }
        vector<ll> ch;
        for (auto c : adj[v]) {
            if (c == p) continue;
            ch.push_back(longest[c] + weight[make_pair(c, v)]);
        }
        if (ch.empty()) return;
        sort(ch.begin(), ch.end(), greater<>());
        puncak[v] = ch[0];
        if (ch.size() > 1) puncak[v] += ch[1];
        longest[v] = ch[0];
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        diameter_ori = max(diameter_ori, puncak[i]);
    }

    const function<void(int, int)> dfs_2 = [&](int v, int p) -> void {
        set<pair<ll, int>, greater<pair<ll, int>>> ch;
        unordered_map<int, ll> lmao;
        for (auto c : adj[v]) {
            if (c == p) continue;
            simpan[c] = simpan[v] + weight[make_pair(c, v)];
            lmao[c] = longest[c] + weight[make_pair(c, v)];
            ch.emplace(lmao[c], c);
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            ch.erase(ch.find(make_pair(lmao[c], c)));
            simpan[c] = max(simpan[c], weight[make_pair(c, v)] + ch.begin()->first);
            ch.emplace(lmao[c], c);
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs_2(c, v);
        }
    };
    dfs_2(0, 0);

    vector<LineContainer> ve(n);
    for (int i = 0; i < n; i++) {
        for (auto c : adj[i]) {
            if (c == par[i]) continue;
            ve[i].add(weight[make_pair(c, i)], longest[c], c);
        }
    }

    int q;
    cin >> q;
    vector<ll> ki(q, -1), ka(q, -1), largest(q, -1);
    vector<pair<int, int>> query(q);
    map<pair<int, int>, vector<pair<int, int>>> yes;
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        --x;
        query[i] = make_pair(x, k);

        pair<ll, int> largest_cht = ve[x].query(k);
        largest[i] = largest_cht.first;
        if (largest_cht.second != -1) {
            yes[make_pair(largest_cht.second, x)].push_back(make_pair(i, k));
        }
    }
    for (int i = 0; i < n; i++) {
        ve[i].clear();
        for (auto c : adj[i]) {
            if (c == par[i]) continue;
            if (!yes[make_pair(c, i)].empty()) {
                for (auto qq : yes[make_pair(c, i)]) {
                    ki[qq.first] = ve[i].query(qq.second).first;
                }
            }
            ve[i].add(weight[make_pair(c, i)], longest[c], c);
        }
        reverse(adj[i].begin(), adj[i].end());
        for (auto c : adj[i]) {
            if (c == par[i]) continue;
            if (!yes[make_pair(c, i)].empty()) {
                for (auto qq : yes[make_pair(c, i)]) {
                    ka[qq.first] = ve[i].query(qq.second).first;
                }
            }
            ve[i].add(weight[make_pair(c, i)], longest[c], c);
        }
    }
    for (int i = 0; i < q; i++) {
        int x = query[i].first, k = query[i].second;
        if (x > 0) {
            ll mx_bawah = max(0ll, largest[i]);
            ll mx_2_bawah = max(0ll, max(ki[i], ka[i]));
            ll mx_atas = simpan[x] + 1ll * (k - 1) * weight[make_pair(x, par[x])];
            ll diam0 = mx_bawah + mx_2_bawah;
            ll diam1 = mx_atas + mx_bawah;
            cout << max(max(diam0, diam1), diameter_ori) << '\n';
        } else {
            ll mx_bawah = max(0ll, largest[i]);
            ll mx_2_bawah = max(0ll, max(ki[i], ka[i]));
            ll diam = mx_bawah + mx_2_bawah;
            cout << max(diam, diameter_ori) << '\n';
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