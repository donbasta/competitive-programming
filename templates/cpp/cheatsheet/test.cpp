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
#define EXPAND(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(__VA_ARGS__))
#define EXPAND1(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EXPAND(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#define LOG(...) cerr << "Line " << __LINE__ << "\n" \
                      << REP(out, __VA_ARGS__) << "\n";

const int INF = 2e9;

void el_psy_congroo() {
    // auto F = [&](int x) -> void { cerr << x + 2 << '\n'; };
    // F(1);
    int a = 10, b = 9, c = 69;
    int d = 10, e = 9, f = 69;
    int g = 10, h = 9, i = 69;
    int j = 10, k = 9, l = 69;
    LOG(a, b, c, d, e, f, g, h, i, j, k, l);
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