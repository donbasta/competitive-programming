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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int sz = s.size();
    int cx = 0, cy = 0, lx = 0, ly = 0;
    int cd = 0, cr = 0;
    for (auto c : s) {
        if (c == 'D')
            cx++, cd++;
        else if (c == 'R')
            cy++, cr++;
    }
    int dx = n - 1 - cx, dy = n - 1 - cy;
    assert(dx >= 0 && dy >= 0);
    if (cd == 0 || cr == 0) {
        cout << n << '\n';
        return;
    }
    char cur = s[0];
    lx = cx, ly = cy;
    cx = cy = 0;
    int sx = -1, sy = -1;
    for (int i = 0; i < sz; i++) {
        if (s[i] == 'D')
            cx++;
        else if (s[i] == 'R')
            cy++;
        if (s[i] != cur) {
            sx = cx, sy = cy;
            break;
        }
    }
    assert(sx != -1 && sy != -1);
    ll vis = sz + 1;
    if (s[0] == 'R') {
        debug(dx, dy, cx, cy, sx, sy);
        vis += 1ll * (dy) * (lx + 1);
        vis += 1ll * (dx) * (ly - sy + 1);
        vis += 1ll * (dx) * (dy);
    } else if (s[0] == 'D') {
        vis += 1ll * (dx) * (ly + 1);
        vis += 1ll * (dy) * (lx - sx + 1);
        vis += 1ll * (dx) * (dy);
    }
    cout << vis << '\n';
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