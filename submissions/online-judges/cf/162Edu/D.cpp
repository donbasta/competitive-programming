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

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), ans(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pre[i] = ar[i] + (i ? pre[i - 1] : 0);
    }
    vector<ll> L(n), R(n);
    L[0] = 0;
    for (int i = 1; i < n; i++) {
        if (ar[i] == ar[i - 1])
            L[i] = L[i - 1];
        else
            L[i] = i;
    }
    R[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (ar[i] == ar[i + 1])
            R[i] = R[i + 1];
        else
            R[i] = i;
    }

    const function<ll(int, int)> range_sum = [&](int a, int b) -> ll {
        return pre[b] - (a ? pre[a - 1] : 0);
    };

    for (int i = 0; i < n; i++) {
        if (((i > 0) && (ar[i - 1] > ar[i])) || ((i < n - 1) && (ar[i] < ar[i + 1]))) {
            ans[i] = 1;
            continue;
        }
        int pl = -1, pr = -1;

        if (i > 0) {
            int l = 0, r = L[i - 1] - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (range_sum(mid, i - 1) > ar[i]) {
                    pl = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        if (i < n - 1) {
            int l = R[i + 1] + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (range_sum(i + 1, mid) > ar[i]) {
                    pr = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        int tmp = INF;
        // debug(i, pl, pr);
        if (pl != -1) {
            tmp = min(tmp, i - pl);
        }
        if (pr != -1) {
            tmp = min(tmp, pr - i);
        }
        if (tmp == INF) tmp = -1;
        ans[i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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