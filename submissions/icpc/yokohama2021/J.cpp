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
    vector<vector<int>> tree;
    int n;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int> &T) {
        if (s == e) {
            tree[v] = vector<int>{T[s]};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    }
    int get_less_than(int v, int s, int e, int l, int r, int que) {
        if (r < l) return 0;
        if (s == l && e == r) {
            return lower_bound(tree[v].begin(), tree[v].end(), que) - tree[v].begin();
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_less_than(v << 1, s, mid, l, r, que);
        else if (l >= mid + 1)
            return get_less_than(v << 1 | 1, mid + 1, e, l, r, que);
        return get_less_than(v << 1, s, mid, l, mid, que) + get_less_than(v << 1 | 1, mid + 1, e, mid + 1, r, que);
    }
    int get_greater_than(int v, int s, int e, int l, int r, int que) {
        if (r < l) return 0;
        if (s == l && e == r) {
            return tree[v].size() - (upper_bound(tree[v].begin(), tree[v].end(), que) - tree[v].begin());
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_greater_than(v << 1, s, mid, l, r, que);
        else if (l >= mid + 1)
            return get_greater_than(v << 1 | 1, mid + 1, e, l, r, que);
        return get_greater_than(v << 1, s, mid, l, mid, que) + get_greater_than(v << 1 | 1, mid + 1, e, mid + 1, r, que);
    }
    int get_max(int v, int s, int e, int l, int r) {
        if (r < l) return -INF;
        if (s == l && e == r) {
            return tree[v].back();
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_max(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get_max(v << 1 | 1, mid + 1, e, l, r);
        return max(get_max(v << 1, s, mid, l, mid), get_max(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<int, int>> V;
    vector<int> ux, uy;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V.emplace_back(x, y);
        ux.push_back(x), uy.push_back(y);
    }
    sort(ux.begin(), ux.end());
    sort(uy.begin(), uy.end());
    ux.resize(unique(ux.begin(), ux.end()) - ux.begin());
    uy.resize(unique(uy.begin(), uy.end()) - uy.begin());

    map<int, int> cmp_x, cmp_y;
    for (int i = 0; i < (int)ux.size(); i++) {
        cmp_x[ux[i]] = i;
    }
    for (int i = 0; i < (int)uy.size(); i++) {
        cmp_y[uy[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        V[i] = make_pair(cmp_x[V[i].first], cmp_y[V[i].second]);
    }
    sort(V.begin(), V.end());

    Segtree sgt(n);
    vector<int> ord(n), abs(n);
    for (int i = 0; i < n; i++) abs[i] = V[i].first, ord[i] = V[i].second;
    sgt.build(1, 0, n - 1, ord);

    vector<pair<int, int>> cand_lb, cand_rb;

    for (int i = 0; i < n; i++) {
        int x = V[i].first, y = V[i].second;
        int lb = lower_bound(abs.begin(), abs.end(), x) - abs.begin();
        // ux[lb] = x, strictly less than y;
        int cnt = sgt.get_less_than(1, 0, n - 1, 0, lb - 1, y);
        if (cnt == 0) {
            cand_lb.emplace_back(x, y);
        }
    }
    for (int i = 0; i < n; i++) {
        int x = V[i].first, y = V[i].second;
        int ub = upper_bound(abs.begin(), abs.end(), x) - abs.begin();
        int cnt = sgt.get_greater_than(1, 0, n - 1, ub, n - 1, y);
        if (cnt == 0) {
            cand_rb.emplace_back(x, y);
        }
    }

    // debug(cand_lb, cand_rb);

    int sz_r = cand_rb.size();
    if (sz_r == 0) {
        cout << 0 << '\n';
        return;
    }
    Segtree sgt_right(sz_r);
    vector<int> ord_r(sz_r), abs_r(sz_r);
    sort(cand_rb.begin(), cand_rb.end());
    for (int i = 0; i < sz_r; i++) abs_r[i] = cand_rb[i].first, ord_r[i] = cand_rb[i].second;
    sgt_right.build(1, 0, sz_r - 1, ord_r);

    sort(V.begin(), V.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    map<pair<int, int>, int> right_bottom;
    right_bottom[V[0]] = -INF;
    int mx = V[0].first;
    for (int i = 1; i < n; i++) {
        if (V[i].second == V[i - 1].second) {
            right_bottom[V[i]] = right_bottom[V[i - 1]];
        } else {
            right_bottom[V[i]] = mx;
        }
        mx = max(mx, V[i].first);
    }

    ll ans = 0;
    // debug(abs);
    for (auto pts : cand_lb) {
        int x = pts.first, y = pts.second;
        int lb = lower_bound(abs.begin(), abs.end(), x) - abs.begin();
        // debug(lb, sgt.get_max(1, 0, n - 1, 0, lb - 1));
        int most_top_left = max(sgt.get_max(1, 0, n - 1, 0, lb - 1), y);
        int most_right_bottom = max(x, right_bottom[make_pair(x, y)]);  // dapet dari map pake iterasi
        // cari banyak titik di cand_right yang
        // absis >= most_right_bottom and ordinat >= most_top_left

        int ab_idx = lower_bound(abs_r.begin(), abs_r.end(), most_right_bottom) - abs_r.begin();
        int cnt = sgt_right.get_greater_than(1, 0, sz_r - 1, ab_idx, sz_r - 1, most_top_left - 1);
        debug(pts, most_right_bottom, most_top_left, cnt);
        ans += cnt;
    }
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