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
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - 1 - i]) {
            cout << "YES" << '\n';
            cout << 1 << '\n';
            cout << s << '\n';
            return;
        }
    }
    char c = s[0];
    int cnt = 0;
    for (auto cc : s) cnt += cc == c;
    if (cnt >= n - 1) {
        cout << "NO" << '\n';
        return;
    }

    int fi = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            fi = i;
            break;
        }
    }
    if (fi == -1) {
        cout << "NO" << '\n';
        return;
    }
    char d = s[fi];
    string test;
    debug(fi);
    if ((n + 1) % (fi + 1) == 0) {
        int rep = (n + 1) / (fi + 1);
        for (int i = 0; i < rep; i++) {
            for (int j = 0; j < fi; j++) {
                test.push_back(c);
            }
            if (i < rep - 1) test.push_back(d);
        }
        if (s == test) {
            if (fi == 1) {
                cout << "NO" << '\n';
                return;
            } else {
                cout << "YES" << '\n';
                cout << 2 << '\n';
                cout << s.substr(0, fi + 2) << ' ' << s.substr(fi + 2, n - fi - 2) << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
    cout << 2 << '\n';
    cout << s.substr(0, fi + 1) << ' ' << s.substr(fi + 1, n - fi - 1) << '\n';
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