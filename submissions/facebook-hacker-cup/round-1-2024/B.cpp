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
const int N = 1e7;

vector<int> P, pre, lp(N + 1);

void init() {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            P.push_back(i);
        }
        for (int j = 0; i * P[j] <= N; j++) {
            lp[i * P[j]] = P[j];
            if (P[j] == lp[i]) break;
        }
    }
    int sz = P.size();
    pre.resize(sz);
    for (int i = 1; i < sz; i++) {
        pre[i] = pre[i - 1];
        if (P[i] - 2 == P[i - 1]) {
            pre[i]++;
        }
    }
}

void el_psy_congroo() {
    int n;
    cin >> n;
    if (n <= 4) {
        cout << 0 << '\n';
        return;
    }
    int idx = upper_bound(P.begin(), P.end(), n) - P.begin();
    cout << (1 + pre[idx - 1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;

    init();
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        el_psy_congroo();
    }

    return 0;
}