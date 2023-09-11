#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

template <typename T, class F = function<T(const T &, const T &)>>
class Segtree {
   public:
    int n;
    vector<T> t;
    F func;

    Segtree(int _n, const F &_f) : n(_n), func(_f) {
        t.assign(4 * _n + 5, INF);
    }
    void build(int v, int s, int e, const vector<T> &ar) {
        if (s == e) {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    void upd(int v, int s, int e, int pos, const T &val) {
        if (s == e) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            upd(v << 1, s, mid, pos, val);
        } else {
            upd(v << 1 | 1, mid + 1, e, pos, val);
        }
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    T que(int v, int s, int e, int l, int r) {
        if (l == s && r == e) {
            return t[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return que(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return que(v << 1 | 1, mid + 1, e, l, r);
        } else {
            return func(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> c(n), le(n, -1), cnt2(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(2, INF));

    int nw = -1;
    for (int i = 0; i < n; i++) {
        if (c[i] != 0)
            le[i] = nw;
        else {
            le[i] = nw;
            nw = i;
        }
    }
    cnt2[0] = (c[0] == 2);
    for (int i = 1; i < n; i++) {
        cnt2[i] = cnt2[i - 1] + (c[i] == 2);
    }

    function<int(int, int)> fmin = [&](int a, int b) -> int { return min(a, b); };
    Segtree<int> sgt(n, fmin);

    dp[0][1] = 1;
    sgt.upd(1, 0, n - 1, 0, 1);
    for (int i = 1; i < n; i++) {
        int x = le[i];
        if (c[i] == 0)
            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
        else {
            if (x >= 1) {
                dp[i][1] = 1 + min(dp[x - 1][0], dp[x - 1][1]);
            } else {
                dp[i][1] = 1;
            }
        }
        if (x <= i - 2) {
            if (cnt2[i - 1] - (x >= 0 ? cnt2[x] : 0) > 0)
                dp[i][0] = 1 + (x >= 1 ? min(dp[x - 1][1], dp[x - 1][0]) : 0);
            else {
                if (i >= 2) dp[i][0] = 1 + sgt.que(1, 0, n - 1, max(x, 0), i - 2);
                if (x == -1) dp[i][0] = 1;
            }
        }
        sgt.upd(1, 0, n - 1, i, min(dp[i][0], dp[i][1]));
        // cout << x << ' ' << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}