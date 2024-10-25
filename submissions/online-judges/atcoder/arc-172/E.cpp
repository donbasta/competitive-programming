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
    vector<int> tree, lz;
    Segtree(int n) : n(n), tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, const string &S) {
        if (s == e) {
            tree[v] = S[s] - '0';
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, S);
        build(v << 1 | 1, mid + 1, e, S);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void push(int v, int s, int e) {
        if (!lz[v]) return;
        lz[v << 1] ^= 1, lz[v << 1 | 1] ^= 1;
        int mid = (s + e) >> 1;
        tree[v << 1] = (mid - s + 1) - tree[v << 1];
        tree[v << 1 | 1] = (e - mid) - tree[v << 1 | 1];
        lz[v] = false;
    }
    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v] = (e - s + 1) - tree[v];
            lz[v] ^= 1;
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
    int que(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return que(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return que(v << 1 | 1, mid + 1, e, l, r);
        return que(v << 1, s, mid, l, mid) + que(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    void upd(int l, int r) {
        upd(1, 0, n - 1, l, r);
    }
    int que(int l, int r) {
        return que(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 1; i < n; i += 2) {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, s);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            sgt.upd(l, r);
        } else {
            int tot = sgt.que(l, r);
            if (tot == 0 || tot == (r - l + 1)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
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