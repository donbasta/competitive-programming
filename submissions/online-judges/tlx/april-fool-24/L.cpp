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

string X = "qwertyuiop";
string Y = "asdfghjkl";
string Z = "zxcvbnm";
int pos[26], group[26];

void el_psy_congroo() {
    char a, b;
    cin >> a >> b;
    if (group[a - 'a'] != group[b - 'a']) {
        cout << "different" << '\n';
    } else {
        cout << abs(pos[a - 'a'] - pos[b - 'a']) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < X.size(); i++) {
        pos[X[i] - 'a'] = i;
        group[X[i] - 'a'] = 0;
    }
    for (int i = 0; i < Y.size(); i++) {
        pos[Y[i] - 'a'] = i;
        group[Y[i] - 'a'] = 1;
    }
    for (int i = 0; i < Z.size(); i++) {
        pos[Z[i] - 'a'] = i;
        group[Z[i] - 'a'] = 2;
    }
    // for (int i = 0; i < 26; i++) {
    //     cerr << (char)(i + 'a') << ' ' << pos[i] << ' ' << group[i] << '\n';
    // }

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}