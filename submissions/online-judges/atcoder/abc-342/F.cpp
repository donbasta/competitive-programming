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

struct BIT {
    vector<ld> tree;
    int n;
    BIT(int n) : n(n), tree(n + 5) {}
    void upd(int idx, ld val) {
        idx++;
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    ld get(int idx) {
        idx++;
        ld ret = 0;
        while (idx) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    ld get(int a, int b) {
        if (a > b) return 0;
        return get(b) - get(a - 1);
    }
};

void el_psy_congroo() {
    int N, L, D;
    cin >> N >> L >> D;

    if (N >= L + 2 * D - 1) {
        cout << 1 << '\n';
        return;
    }

    int sz = max(L + D, N);
    BIT P(sz + 5), Q(sz + 5);

    Q.upd(0, 1);
    for (int i = 1; i <= L + D - 1; i++) {
        int a = max(i - D, 0), b = min(i - 1, L - 1);
        ld now = Q.get(a, b) / ld(D);
        Q.upd(i, now);
    }
    P.upd(0, 1);
    for (int i = 1; i <= sz; i++) {
        int a = max(i - D, 0), b = i - 1;
        ld now = P.get(a, b) / ld(D);
        P.upd(i, now);
    }
    ld ans = Q.get(N + 1, L + D - 1);
    // ld ans = P.get(L, L) * Q.get(N + 1, L + D - 1);
    for (int i = L + 1; i <= N; i++) {
        ld tmp = P.get(i, i);
        ld sec = Q.get(L, min(i - 1, L + D - 1));
        sec += Q.get(N + 1, L + D - 1);
        ans = max(ans, tmp * sec);
    }
    cout << fixed << setprecision(15) << ans << '\n';
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