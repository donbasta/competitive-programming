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
    vector<ll> A(n + 2), D(n + 2), def(n + 2);
    vector<int> prv(n + 2), nx(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        prv[i] = i - 1;
        nx[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        def[i] = A[i - 1] + A[i + 1] - D[i];
    }
    queue<int> Q;
    vector<int> day_dies(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        if (def[i] > 0) {
            Q.emplace(i);
            day_dies[i] = 1;
        }
    }
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        if (prv[now] > 0) {
            def[prv[now]] += A[nx[now]] - A[now];
            nx[prv[now]] = nx[now];
            if (def[prv[now]] > 0 && day_dies[nx[now]] == -1 && day_dies[prv[now]] == -1) {
                Q.emplace(prv[now]);
                day_dies[prv[now]] = day_dies[now] + 1;
            }
        }
        if (nx[now] <= n) {
            def[nx[now]] += A[prv[now]] - A[now];
            prv[nx[now]] = prv[now];
            if (def[nx[now]] > 0 && day_dies[prv[now]] == -1 && day_dies[nx[now]] == -1) {
                Q.emplace(nx[now]);
                day_dies[nx[now]] = day_dies[now] + 1;
            }
        }
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        if (day_dies[i] != -1) cnt[day_dies[i]]++;
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
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