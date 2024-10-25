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
    vector<ll> tree;
    Segtree(int n) : tree(4 * n + 5) {}
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
    ll get_min(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_min(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get_min(v << 1 | 1, mid + 1, e, l, r);
        return min(
            get_min(v << 1, s, mid, l, mid),
            get_min(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), pre(n);
    ll mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pre[i] = ar[i] + (i ? pre[i - 1] : 0);
        mx = max(mx, ar[i]);
    }
    ll lo = mx, hi = 1e18;
    ll ans = -1;

    const function<ll(int, int)> range_sum = [&](int a, int b) -> ll {
        if (a > b) return 0;
        return pre[b] - (a ? pre[a - 1] : 0);
    };

    const ll INF = 1e18;
    const function<bool(ll)> ok = [&](ll x) -> bool {
        vector<ll> dp(n, INF);
        Segtree sgt(n);
        dp[0] = ar[0];
        sgt.upd(1, 0, n - 1, 0, dp[0]);
        int far_left = 0;
        for (int i = 1; i < n; i++) {
            while (far_left <= i - 1 && range_sum(far_left, i - 1) > x) {
                far_left++;
            }
            if (far_left == 0) {
                dp[i] = ar[i];
            } else {
                dp[i] = ar[i] + sgt.get_min(1, 0, n - 1, far_left - 1, i - 1);
            }
            sgt.upd(1, 0, n - 1, i, dp[i]);
        }
        // debug(x);
        // debug(dp);
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (dp[i] <= x && range_sum(i + 1, n - 1) <= x) {
                ans = true;
            }
        }
        // debug(ans);
        return ans;
    };

    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
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