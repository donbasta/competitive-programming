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

struct SegmentTree {
    vector<vector<int>> tree;
    SegmentTree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, vector<vector<int>> &A) {
        if (s == e) {
            tree[v] = A[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, A);
        build(v << 1 | 1, mid + 1, e, A);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    };
    int query(int v, int s, int e, int l, int r, int v1, int v2) {
        if (l > r) return 0;
        if (s == l && e == r) {
            return upper_bound(tree[v].begin(), tree[v].end(), v2) - lower_bound(tree[v].begin(), tree[v].end(), v1);
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return query(v << 1, s, mid, l, r, v1, v2);
        else if (l >= mid + 1)
            return query(v << 1 | 1, mid + 1, e, l, r, v1, v2);
        return query(v << 1, s, mid, l, mid, v1, v2) + query(v << 1 | 1, mid + 1, e, mid + 1, r, v1, v2);
    }
};

void el_psy_congroo() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<int> rows;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ve.emplace_back(x, y);
        rows.push_back(x);
    }
    sort(rows.begin(), rows.end());
    rows.resize(unique(rows.begin(), rows.end()) - rows.begin());
    map<int, int> mp;
    int sz = rows.size();
    for (int i = 0; i < sz; i++) {
        mp[rows[i]] = i;
    }
    vector<vector<int>> ar(sz);
    for (auto e : ve) {
        ar[mp[e.first]].push_back(e.second);
    }
    for (int i = 0; i < sz; i++) {
        sort(ar[i].begin(), ar[i].end());
    }
    SegmentTree st(sz);
    st.build(1, 0, sz - 1, ar);

    vector<int> sk(2);
    int x1 = 1, x2 = a, y1 = 1, y2 = b;
    for (int i = 0; i < m; i++) {
        char mv;
        int k;
        cin >> mv >> k;
        int skor;
        if (mv == 'D') {
            // x2... x2 - k + 1
            int p = lower_bound(rows.begin(), rows.end(), x2 - k + 1) - rows.begin();
            int q = upper_bound(rows.begin(), rows.end(), x2) - rows.begin() - 1;
            skor = st.query(1, 0, sz - 1, p, q, y1, y2);
            x2 -= k;
        } else if (mv == 'U') {
            int p = lower_bound(rows.begin(), rows.end(), x1) - rows.begin();
            int q = upper_bound(rows.begin(), rows.end(), x1 + k - 1) - rows.begin() - 1;
            skor = st.query(1, 0, sz - 1, p, q, y1, y2);
            x1 += k;
        } else if (mv == 'L') {
            int p = lower_bound(rows.begin(), rows.end(), x1) - rows.begin();
            int q = upper_bound(rows.begin(), rows.end(), x2) - rows.begin() - 1;
            skor = st.query(1, 0, sz - 1, p, q, y1, y1 + k - 1);
            y1 += k;
        } else if (mv == 'R') {
            int p = lower_bound(rows.begin(), rows.end(), x1) - rows.begin();
            int q = upper_bound(rows.begin(), rows.end(), x2) - rows.begin() - 1;
            skor = st.query(1, 0, sz - 1, p, q, y2 - k + 1, y2);
            y2 -= k;
        }
        debug(i, skor);
        sk[i & 1] += skor;
    }
    cout << sk[0] << ' ' << sk[1] << '\n';
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