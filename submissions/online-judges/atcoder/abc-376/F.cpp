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

struct Segtree {
    int n;
    vector<ll> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    // const ll INF = 2e18;
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return min(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, ll val) {
        upd(1, 0, n - 1, idx, val);
    }
    ll get(int l, int r) {
        if (l > r) return INF;
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> dp(n, INF), pd(n);
    dp[1] = 0;
    Segtree s1(3 * n), s2(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        s1.upd(i, dp[i % n] - i);
        s2.upd(i, dp[i % n] + i);
    }
    char last_h = 'L';
    int last_t = 0;

    auto solve = [&](int a, int b, int c) -> ll {
        // over all k, find minimum value of
        // dp[k] + calc(a->b, k->c);
        ll ans = INF;
        ll ab1 = n - abs(a - b), ab2 = abs(a - b);
        if (c < min(a, b)) {
            ll kiri = (c + n) + s1.get(max(a, b) + 1, c + n);
            ll kanan = s2.get(c + n + 1, min(a, b) - 1) - (c + n);
            ans = min(ans, min(kiri, kanan) + abs(a - b));

            ll kiri_dalam = s2.get(min(a, b) + 1 + n, max(a, b) + 1 + n) - (c + n);
            ll kanan_dalam = (c + 2 * n) + s1.get(min(a, b) + 1 + n, max(a, b) + 1 + n);
            if (a < b) {
                ans = min(ans, kiri_dalam + ab1);
                ans = min(ans, kanan_dalam + ab2);
            } else {
                ans = min(ans, kiri_dalam + ab2);
                ans = min(ans, kanan_dalam + ab1);
            }
        } else if (c > max(a, b)) {
            ll kiri = (c + n) + s1.get(max(a, b) + n + 1, c + n);
            ll kanan = s2.get(c + n + 1, min(a, b) + 2 * n - 1) - (c + n);
            ans = min(ans, min(kiri, kanan) + abs(a - b));

            ll kiri_dalam = s2.get(min(a, b) + 1 + n, max(a, b) + 1 + n) - c;
            ll kanan_dalam = (c + n) + s1.get(min(a, b) + 1 + n, max(a, b) + 1 + n);
            if (a < b) {
                ans = min(ans, kiri_dalam + ab1);
                ans = min(ans, kanan_dalam + ab2);
            } else {
                ans = min(ans, kiri_dalam + ab2);
                ans = min(ans, kanan_dalam + ab1);
            }
        } else {
            ll kiri_dalam = (c + n) + s1.get(min(a, b) + n + 1, c + n);
            ll kanan_dalam = s2.get(c + n + 1, max(a, b) + n - 1) - (c + n);
            ans = min(ans, min(kiri_dalam, kanan_dalam) + ab1);

            ll kiri_luar = (c + n) + s1.get(max(a, b) + 1, min(a, b) - 1 + n);
            ll kanan_luar = s2.get(max(a, b) + n + 1, min(a, b) + 2 * n - 1) - (c + n);
            ans = min(ans, min(kiri_luar, kanan_luar) + ab2);
        }
        return ans;
    };

    for (int i = 0; i < q; i++) {
        char h;
        int t;
        cin >> h >> t;
        --t;
        if (h == last_h) {
            for (int j = 0; j < n; j++) {
                if (j == t)
                    pd[j] = INF;
                else
                    pd[j] = solve(last_t, t, j);
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (j == t)
                    pd[j] = INF;
                else
                    pd[j] = solve(last_t, j, t);
            }
        }
        last_h = h, last_t = t;
        dp.swap(pd);
        for (int i = 0; i < 3 * n; i++) {
            s1.upd(i, dp[i % n] - i);
            s2.upd(i, dp[i % n] + i);
        }
        // cout << "after query " << i << '\n';
        // for (int i = 0; i < n; i++) {
        //     cout << i << ' ' << dp[i] << '\n';
        // }
        // cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
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