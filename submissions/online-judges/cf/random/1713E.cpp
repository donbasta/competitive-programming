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

struct DSU {
    int n;
    vector<int> par;
    DSU(int n) : n(n), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (par[x] == x ? x : par[x] = fpar(par[x]));
    }
    void unite(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[x] = y;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    int ar[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }
    DSU dsu(2 * n);
    vector<bool> col(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[i][j] < ar[j][i]) {
                if (!(col[i] && col[j])) {
                    dsu.unite(2 * i, 2 * j);
                    dsu.unite(2 * j + 1, 2 * i + 1);
                    col[i] = col[j] = true;
                } else {
                    if (dsu.fpar(2 * i) == dsu.fpar(2 * j + 1)) {
                        assert(dsu.fpar(2 * i + 1) == dsu.fpar(2 * j));
                        swap(ar[i][j], ar[j][i]);
                    }
                }
            } else if (ar[i][j] > ar[j][i]) {
                if (!(col[i] && col[j])) {
                    dsu.unite(2 * i, 2 * j + 1);
                    dsu.unite(2 * j, 2 * i + 1);
                    swap(ar[i][j], ar[j][i]);
                    col[i] = col[j] = true;
                } else {
                    if (dsu.fpar(2 * i) == dsu.fpar(2 * j + 1)) {
                        assert(dsu.fpar(2 * i + 1) == dsu.fpar(2 * j));
                        swap(ar[i][j], ar[j][i]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
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