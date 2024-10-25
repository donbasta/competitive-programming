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
    vector<int> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (l > r) return 0;
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        else {
            return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    set<int> unq;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        unq.insert(ar[i]);
    }
    int id = 0;
    for (auto e : unq) mp[e] = id++;
    for (int i = 0; i < n; i++) {
        ar[i] = mp[ar[i]];
    }
    // debug(ar);

    Segtree s1(id), s2(id);
    vector<int> L(n), R(n);
    int LIS = 1;
    for (int i = 0; i < n; i++) {
        int mx = s1.get(1, 0, id - 1, 0, ar[i] - 1);
        L[i] = mx;
        LIS = max(LIS, mx + 1);
        s1.upd(1, 0, id - 1, ar[i], mx + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        int mx = s2.get(1, 0, id - 1, ar[i] + 1, id - 1);
        R[i] = mx;
        s2.upd(1, 0, id - 1, ar[i], mx + 1);
    }
    // debug(LIS);
    // debug(L);
    // debug(R);

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        if (L[i] + R[i] + 1 == LIS) {
            ret.push_back(i);
        }
    }
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << (e + 1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}