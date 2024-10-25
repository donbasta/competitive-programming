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

using pll = pair<ll, ll>;

pll operator+(pll a, pll b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

struct Segtree {
    int n;
    vector<pll> tree, lz;
    Segtree(int n) : n(n), tree(4 * n + 5), lz(4 * n + 5) {}
    void push(int v, int s, int e) {
        if (lz[v].second == 0) return;
        int mid = (s + e) >> 1;
        lz[v << 1] = (lz[v << 1] + lz[v]);
        lz[v << 1 | 1] = (lz[v << 1 | 1] + lz[v]);
        tree[v << 1] = (tree[v << 1] + make_pair((mid - s + 1) * lz[v].first, (mid - s + 1) * lz[v].second));
        tree[v << 1 | 1] = (tree[v << 1 | 1] + make_pair((e - mid) * lz[v].first, (e - mid) * lz[v].second));
        lz[v].first = lz[v].second = 0;
    }
    void upd(int v, int s, int e, int l, int r, ll val) {
        if (s == l && e == r) {
            tree[v] = (tree[v] + make_pair(val * (e - s + 1), e - s + 1));
            lz[v] = (lz[v] + make_pair(val, 1));
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    pll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    void upd(int l, int r, ll val) {
        upd(1, 0, n - 1, l, r, val);
    }
    pll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    vector<ll> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    vector<ll> ord(n), idx(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) -> bool {
        return R[a] - L[a] > R[b] - L[b];
    });
    for (int i = 0; i < n; i++) {
        idx[ord[i]] = i;
    }
    Segtree sgt(n + 1);

    ll tot = 0, ret = INF, count_one = 0;
    for (int i = 0; i < n; i++) {
        ll cur_len = R[i] - L[i] + 1;
        tot += cur_len;
        if (tot < k) {
            if (cur_len > 1) {
                sgt.upd(idx[i] + 1, n, cur_len);
            }
            count_one += cur_len == 1;
            continue;
        }
        // find most right s.t. sumnya <= k - 1;
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll cek = sgt.get(0, mid).first;
            if (cek <= k - 1) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        assert(ans != -1);
        pll T = sgt.get(0, ans);
        ll covered = T.first;
        ll steps;
        if (covered + cur_len >= k) {
            steps = (L[i] - 1) + 2ll * T.second + 2 + (k - covered);
        } else {
            if (count_one >= k - covered - cur_len) {
                steps = (L[i] - 1) + 2ll * T.second + 2 + cur_len + 2ll * (k - covered - cur_len);
            } else {
                steps = INF;
            }
        }
        ret = min(ret, steps);
        if (cur_len > 1) {
            sgt.upd(idx[i] + 1, n, cur_len);
        }
        count_one += cur_len == 1;
    }
    if (ret == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << ret << '\n';
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