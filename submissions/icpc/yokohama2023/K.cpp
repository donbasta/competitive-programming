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

const int M = 1e5;
const int B = 199;
const ld eps = 1e-6;

ld query(int a, int b, int c, int d) {
    cout << "query " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    ld ret;
    cin >> ret;
    return ret;
}

void el_psy_congroo() {
    vector<pair<ld, int>> H, V;
    for (int i = B; i < M; i += B) {
        ld q = query(i, 0, i, M);
        if (q < eps) continue;
        V.emplace_back(q, i);
    }
    for (int i = B; i < M; i += B) {
        ld q = query(0, i, M, i);
        if (q < eps) continue;
        H.emplace_back(q, i);
    }
    assert(!H.empty());
    assert(!V.empty());
    if (V.size() == 1) {
        int x = V.back().second;
        ld q = query(x + 1, 0, x + 1, M);
        if (q >= eps) {
            V.emplace_back(q, x + 1);
        } else {
            q = query(x - 1, 0, x - 1, M);
            assert(q >= eps);
            V.emplace_back(q, x - 1);
        }
    }
    if (H.size() == 1) {
        int x = H.back().second;
        ld q = query(0, x + 1, M, x + 1);
        if (q >= eps) {
            H.emplace_back(q, x + 1);
        } else {
            q = query(0, x - 1, M, x - 1);
            assert(q >= eps);
            H.emplace_back(q, x - 1);
        }
    }
    int hhh, vvv, radius;
    {
        ld p1 = V[0].first / 2, x1 = V[0].second;
        ld p2 = V[1].first / 2, x2 = V[1].second;
        if (x1 > x2) swap(x1, x2), swap(p1, p2);
        ld L = x2 - x1;
        ld A = (p2 * p2 - p1 * p1 + ld(L) * ld(L)) / (ld(L) * 2);
        ld hori = x1 + A;
        hhh = roundl(hori);

        ld rad = hypot(A, p1);
        radius = roundl(rad);
    }
    {
        ld p1 = H[0].first / 2, x1 = H[0].second;
        ld p2 = H[1].first / 2, x2 = H[1].second;
        if (x1 > x2) swap(x1, x2), swap(p1, p2);
        ld L = x2 - x1;
        ld A = (p2 * p2 - p1 * p1 + ld(L) * ld(L)) / (ld(L) * 2);
        ld ver = x1 + A;
        vvv = roundl(ver);
        // assert(radius == (int)roundl(hypot(A, p1)));
    }
    cout << "answer " << hhh << ' ' << vvv << ' ' << radius << endl;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}