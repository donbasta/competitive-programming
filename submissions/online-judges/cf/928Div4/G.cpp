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
    vector<vector<int>> chd(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        --x;
        chd[x].push_back(i);
    }
    string s;
    cin >> s;
    vector<int> dp1(n, INF), dp2(n, INF);
    const function<void(int)> dfs = [&](int v) {
        for (auto c : chd[v]) {
            dfs(c);
        }
        int tmp1 = 0, tmp2 = 0;
        for (auto c : chd[v]) {
            tmp1 += min(dp1[c], 1 + dp2[c]);
            tmp2 += min(dp2[c], 1 + dp1[c]);
        }
        if (s[v] == 'P') {
            dp1[v] = tmp1;
        } else if (s[v] == 'S') {
            dp2[v] = tmp2;
        } else if (s[v] == 'C') {
            dp1[v] = tmp1, dp2[v] = tmp2;
        }
    };
    dfs(0);
    cout << min(dp1[0], dp2[0]) << '\n';
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