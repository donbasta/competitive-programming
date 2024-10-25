#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree1 {
    vector<int> tree;
    vector<bool> lz;
    Segtree1(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void push(int v, int s, int e) {
        if (!lz[v]) return;
        int mid = (s + e) >> 1;
        lz[v << 1] = lz[v << 1 | 1] = true;
        tree[v << 1] = mid - s + 1;
        tree[v << 1 | 1] = e - mid;
        lz[v] = false;
    }
    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v] = e - s + 1;
            lz[v] = true;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r);
        else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

pair<int, int> merge(const pair<int, int>& x, const pair<int, int>& y) {
    return make_pair(min(x.first, y.first), max(x.second, y.second));
}

struct Segtree2 {
    vector<pair<int, int>> tree;  // min, max
    Segtree2(int n) : tree(4 * n + 5, make_pair(INF, -INF)) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = make_pair(val, val);
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return merge(
            get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    Segtree1 isBlack(n);
    Segtree2 whiteIntervals(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            if (x == 0) {
                isBlack.upd(1, 0, n - 1, l, r);
            } else {
                // insert white interval, no need to insert if it completely encloses another interval
                if (whiteIntervals.get(1, 0, n - 1, l, r).first <= r) {
                    continue;
                } else {
                    whiteIntervals.upd(1, 0, n - 1, l, r);
                }
            }
        } else {
            int idx;
            cin >> idx;
            --idx;
            if (isBlack.get(1, 0, n - 1, idx, idx) == 1) {
                cout << "NO" << '\n';
            } else {
                // if idx is not contained in any white intervals, then N/A
                if (whiteIntervals.get(1, 0, n - 1, 0, idx).second < idx) {
                    cout << "N/A" << '\n';
                } else {
                    // find leftmost i s.t. i to idx - 1 is coloured black, otherwise i = idx
                    // find rightmost j s.t. idx + 1 to j is coloured black, otherwise j = idx
                    // find out white segments with left endpoint in [i, idx] and right endpoint in [idx, j]
                    // if exist, answer is YES, otherwise N/A
                    int le = idx, ri = idx;
                    int lo = 0, hi = idx - 1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (isBlack.get(1, 0, n - 1, mid, idx - 1) == idx - mid) {
                            le = mid;
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    lo = idx + 1, hi = n - 1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (isBlack.get(1, 0, n - 1, idx + 1, mid) == mid - idx) {
                            ri = mid;
                            lo = mid + 1;
                        } else {
                            hi = mid - 1;
                        }
                    }
                    int L = le, R = idx, bat = -INF;
                    while (L <= R) {
                        int mid = (L + R) >> 1;
                        pair<int, int> q = whiteIntervals.get(1, 0, n - 1, L, mid);
                        if (q.second > ri) {
                            R = mid - 1;
                        } else {
                            if (q.second != -INF) bat = q.second;
                            L = mid + 1;
                        }
                    }
                    if (bat != -INF && bat >= idx) {
                        cout << "YES" << '\n';
                    } else {
                        cout << "N/A" << '\n';
                    }
                }
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
        el_psy_congroo();
    }

    return 0;
}