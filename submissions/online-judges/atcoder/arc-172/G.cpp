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
    vector<ll> A(n + 1), P(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        P[i] = A[i] + P[i - 1];
    }
    vector<int> nx(n + 1);
    vector<int> id;
    id.push_back(n);

    const function<bool(int, int, int)> left = [&](int a, int b, int c) -> bool {
        ll dx1 = b - a, dy1 = P[b] - P[a];
        ll dx2 = c - b, dy2 = P[c] - P[b];
        ll cp = dx1 * dy2 - dy1 * dx2;
        return cp > 0;
    };

    for (int i = n - 1; i >= 0; i--) {
        while (id.size() >= 2 && left(i, id.back(), id[id.size() - 2])) {
            id.pop_back();
        }
        nx[i] = id.back();
        id.push_back(i);
    }
    vector<ld> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ld(P[nx[i - 1]] - P[i - 1]) / ld(nx[i - 1] - i + 1);
    }
    cout << fixed << setprecision(10);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
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