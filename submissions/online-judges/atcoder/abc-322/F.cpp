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

struct node {
    int mx[2], mx_pref[2], mx_suf[2];
    int len;
    node() {}
    node(int val) {
        mx[val] = mx_pref[val] = mx_suf[val] = 1;
        mx[val ^ 1] = mx_pref[val ^ 1] = mx_suf[val ^ 1] = 0;
        len = 1;
    }
    void reverse() {
        swap(mx[0], mx[1]);
        swap(mx_pref[0], mx_pref[1]);
        swap(mx_suf[0], mx_suf[1]);
    }
};

node merge(node a, node b) {
    node ret;
    ret.len = a.len + b.len;
    for (int i = 0; i < 2; i++) {
        ret.mx[i] = max(a.mx[i], b.mx[i]);
        ret.mx[i] = max(ret.mx[i], a.mx_suf[i] + b.mx_pref[i]);

        ret.mx_pref[i] = a.mx_pref[i];
        if (a.mx_pref[i] == a.len) {
            ret.mx_pref[i] = max(ret.mx_pref[i], a.len + b.mx_pref[i]);
        }

        ret.mx_suf[i] = b.mx_suf[i];
        if (b.mx_suf[i] == b.len) {
            ret.mx_suf[i] = max(ret.mx_suf[i], b.len + a.mx_suf[i]);
        }
    }
    return ret;
}

struct Segtree {
    int n;
    vector<node> tree;
    vector<int> lz;
    Segtree(int n) : n(n), tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, string &S) {
        if (s == e) {
            tree[v] = node(S[s] - '0');
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, S);
        build(v << 1 | 1, mid + 1, e, S);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v) {
        if (!lz[v]) return;
        lz[v] = 0;
        tree[v << 1].reverse();
        tree[v << 1 | 1].reverse();
        lz[v << 1] ^= 1;
        lz[v << 1 | 1] ^= 1;
    }
    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v].reverse();
            lz[v] ^= 1;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            upd(v << 1 | 1, mid + 1, e, l, r);
        } else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
    node get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return merge(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int l, int r) {
        upd(1, 0, n - 1, l, r);
    }
    node get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, s);

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        --l, --r;
        if (c == 1) {
            sgt.upd(l, r);
        } else if (c == 2) {
            cout << sgt.get(l, r).mx[1] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}