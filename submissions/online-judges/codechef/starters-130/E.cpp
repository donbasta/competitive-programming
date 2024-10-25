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

const ll INF = 2e18;
const int M = 2e6;

int lp[M + 1], F[M + 1], mx[M + 1], mx_pref[M + 1];
int maxF = 0;
vector<int> pr;

void init() {
    for (int i = 2; i <= M; i++) {
        if (lp[i] == 0) {
            F[i] = 1;
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= M; j++) {
            lp[i * pr[j]] = pr[j];
            F[i * pr[j]] = F[i] + 1;
            if (pr[j] == lp[i]) break;
        }
    }
    for (int i = 1; i <= M; i++) {
        mx[F[i]] = max(mx[F[i]], i);
    }
    mx_pref[0] = mx[0];
    for (int i = 1; i <= M; i++) {
        maxF = max(maxF, F[i]);
        mx_pref[i] = max(mx_pref[i - 1], mx[i]);
    }
}

struct SparseTable {
    const int K = 22;
    vector<vector<int>> table;
    int n;
    SparseTable() : n(M) {
        build();
    }
    void build() {
        table.resize(K + 1);
        for (auto &v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = F[i + 1];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return min(table[i][l], table[i][r - (1 << i) + 1]);
    }
} st;

struct Segtree {
    vector<int> tree;
    void resize(int n) {
        tree.resize(4 * n + 5);
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = max(tree[v], val);
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) {
            upd(v << 1, s, mid, idx, val);
        } else if (idx >= mid + 1) {
            upd(v << 1 | 1, mid + 1, e, idx, val);
        }
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

const int N = 2e5;
int n[N + 1], m[N + 1], k[N + 1], A[N + 1], B[N + 1];
int piv2[N + 1], piv3[N + 1], val2[N + 1], val3[N + 1], val4[N + 1];
ll tot[N + 1];

void input(int idx) {
    cin >> n[idx] >> m[idx] >> k[idx];
    vector<ll> ar(n[idx]), f_cur(n[idx]);
    for (int i = 0; i < n[idx]; i++) cin >> ar[i];
    tot[idx] = accumulate(ar.begin(), ar.end(), 0ll);
    for (int i = 0; i < n[idx]; i++) {
        f_cur[i] = F[ar[i]];
    }
    sort(f_cur.begin(), f_cur.end());
    A[idx] = f_cur[n[idx] - 2], B[idx] = f_cur.back();
}

void el_psy_congroo(int idx) {
    ll ans = -INF;
    int L = 1, R = m[idx], piv = -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (st.get(mid - 1, m[idx] - 1) > A[idx]) {
            R = mid - 1;
        } else {
            piv = mid;
            L = mid + 1;
        }
    }
    if (piv != -1) {
        ans = max(ans, tot[idx] + 1ll * k[idx] * piv - A[idx] - B[idx]);
        ans = max(ans, tot[idx] + 1ll * (k[idx] - 1) * piv - B[idx] + val2[idx]);
        // ans = max(ans, tot[idx] + 1ll * (k[idx] - 1) * piv + piv2[idx] - B[idx] - F[piv2[idx]]);
    }
    ans = max(ans, tot[idx] + 1ll * (k[idx] - 2) * m[idx] + 2ll * val3[idx]);
    if (k[idx] == 2) {
        ans = max(ans, tot[idx] + 2ll * val4[idx]);
    }
    // ans = max(ans, tot[idx])
    // ans = max(ans, tot[idx] + 1ll * (k[idx] - 2) * m[idx] + 2ll * piv3[idx] - 2ll * F[piv3[idx]]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    sgt.resize(maxF + 1);
    st.build();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        input(i);
    }

    vector<vector<int>> queries[N + 5];
    for (int i = 1; i <= TC; i++) {
        queries[m[i]].push_back(vector<int>{i, 2, A[i] + 1});
        queries[m[i]].push_back(vector<int>{i, 3, max(B[i] + 1, F[m[i]])});
        queries[m[i]].push_back(vector<int>{i, 4, B[i] + 1});
    }
    for (int i = 1; i <= N; i++) {
        sgt.upd(1, 0, maxF, F[i], i - F[i]);
        for (auto q : queries[i]) {
            int mx = sgt.get(1, 0, maxF, q[2], maxF);
            if (q[1] == 2) {
                val2[q[0]] = mx;
            } else if (q[1] == 3) {
                val3[q[0]] = mx;
            } else if (q[1] == 4) {
                val4[q[0]] = mx;
            }
        }
    }
    // process offline here
    for (int i = 1; i <= TC; i++) {
        // debug(val2[i], val3[i]);
        el_psy_congroo(i);
    }

    return 0;
}