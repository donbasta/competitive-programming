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

vector<string> solve(int dig) {
    if (dig == 3) {
        return vector<string>{
            "169", "196", "961"};
    }
    vector<string> prv = solve(dig - 2);
    vector<string> ret;
    for (auto e : prv) {
        string tmp = e;
        e.push_back('0');
        e.push_back('0');
        ret.push_back(e);
    }
    int mid = (dig - 3) / 2;
    string a, ra;
    a.push_back('9');
    for (int i = 0; i < mid; i++) a.push_back('0');
    a.push_back('6');
    for (int i = 0; i < mid; i++) a.push_back('0');
    a.push_back('1');
    ra = a;
    reverse(ra.begin(), ra.end());
    ret.push_back(a);
    ret.push_back(ra);
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 3) {
        cout << 169 << '\n';
        cout << 196 << '\n';
        cout << 961 << '\n';
        return;
    }

    vector<string> ans = solve(n);
    for (auto st : ans) {
        cout << st << '\n';
    }
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