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
    ll A[3][3];
    ll tot = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
            tot += A[i][j];
        }
    }
    bool lmao = true;
    for (int rw = 0; rw < 3; rw++) {
        for (int i = 0; i < 27; i++) {
            vector<vector<int>> col(3, vector<int>(3));
            vector<int> pp = {i % 3, (i / 3) % 3, (i / 9) % 3};
            for (int j = 0; j < 3; j++) {
                if (rw == j) {
                    col[j][pp[j]] = 1;
                } else {
                    col[j][(pp[j] + 1) % 3] = col[j][(pp[j] + 2) % 3] = 1;
                }
            }
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                int tot = col[j][0] + col[j][1] + col[j][2];
                if (tot == 3) ok = false;
                tot = col[0][j] + col[1][j] + col[2][j];
                if (tot == 3) ok = false;
            }
            if (col[0][0] + col[1][1] + col[2][2] == 3) ok = false;
            if (col[0][2] + col[1][1] + col[2][0] == 3) ok = false;
            if (ok) {
                ll Taka = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (col[i][j]) Taka += A[i][j];
                    }
                }
                lmao &= (Taka * 2 < tot);
            }
        }
    }
    if (lmao) {
        cout << "Aoki" << '\n';
    } else {
        cout << "Takahashi" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}