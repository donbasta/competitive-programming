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

ll G(ll x) {  // 0 xor 1 xor ... xor x
    ll r4 = x % 4;
    if (r4 == 0)
        return x;
    else if (r4 == 1)
        return 1;
    else if (r4 == 2)
        return x + 1;
    return 0;
}

ll PG(ll x) {  // G(0) xor G(1) xor ... xor G(x)
    ll r4 = x % 8;
    ll x8 = x - r4;
    if (r4 == 0)
        return x8;
    else if (r4 == 1)
        return (x8 ^ 1);
    else if (r4 == 2)
        return 2;
    else if (r4 == 3)
        return 2;
    else if (r4 == 4)
        return ((x8 + 4) ^ 2);
    else if (r4 == 5)
        return ((x8 + 4) ^ 3);
    else if (r4 == 6)
        return 0;
    return 0;
}

ll F(ll x, ll y) {
    ll ret = PG(x + y);
    if (x) ret = (ret ^ PG(x - 1));
    if (y) ret = (ret ^ PG(y - 1));
    return ret;
}

void el_psy_congroo() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll ret = F(x - 1, y - 1) ^ F(x - 1, m - y) ^ F(n - x, y - 1) ^ F(n - x, m - y);
    ret = (ret ^ G(x - 1) ^ G(y - 1) ^ G(n - x) ^ G(m - y));
    cout << ret << '\n';
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