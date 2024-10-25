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

// s = len(n)
// an-b = floor(n(1 + 10^s + ... + 10^(s(a-1))) / 10^b)

// LHS punya maks 4+s digit
// RHS punya as-b digit

// as-b <= 4+s <= 7
// as - 1 >= b >= as - 4 - s

// s(a-1) <= 4+b

void el_psy_congroo() {
    int n;
    cin >> n;
    string sn = to_string(n);
    int s = sn.length();
    int ans = 0;
    vector<pair<int, int>> ret;
    for (int a = 1; a <= 10000; a++) {
        for (int b = min(10000, a * s - 1); b >= max(1, a * s - 4 - s); b--) {
            int cek = n * a - b;
            string scek = to_string(cek);
            if (cek <= 0 || scek.length() != a * s - b) continue;
            bool ok = true;
            int ptr = 0;
            for (int j = 0; j < scek.length(); j++) {
                if (scek[j] != sn[ptr]) {
                    ok = false;
                    break;
                }
                ptr = (ptr + 1) % s;
            }
            ans += ok;
            if (ok) ret.emplace_back(a, b);
        }
    }
    cout << ans << '\n';
    for (auto e : ret) {
        cout << e.first << ' ' << e.second << '\n';
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