#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<pair<int, int>> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = make_pair(T[s], s);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> p(n), id(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        id[p[i]] = i;
    }
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, p);

    ll ans = 0;
    const function<void(int, int)> solve = [&](int l, int r) {
        if (l > r) return;
        if (r - l + 1 <= 2) return;
        pair<int, int> pt = sgt.get(1, 0, n - 1, l, r);
        int idx = pt.second, val = pt.first;
        solve(l, idx - 1);
        solve(idx + 1, r);
        int ki = idx - l;
        int ka = r - idx;
        if (ki <= ka) {
            for (int i = l; i <= idx - 1; i++) {
                ans += (id[val - 1 - p[i]] >= (idx + 1) && id[val - 1 - p[i]] <= r);
            }
        } else {
            for (int i = idx + 1; i <= r; i++) {
                ans += (id[val - 1 - p[i]] >= l && id[val - 1 - p[i]] <= (idx - 1));
            }
        }
    };

    solve(0, n - 1);
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