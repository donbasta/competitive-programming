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
    int n, h, w;
    cin >> n >> h >> w;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve.emplace_back(a, b);
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    bool ok = false;
    do {
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<bool>> isi(h, vector<bool>(w));
            bool cant = false;
            for (int k = 0; k < n; k++) {
                int x = -1, y = -1;
                bool found = false;
                for (int ii = 0; ii < h; ii++) {
                    for (int jj = 0; jj < w; jj++) {
                        if (isi[ii][jj]) {
                            continue;
                        }
                        x = ii;
                        y = jj;
                        found = true;
                        break;
                    }
                    if (found) break;
                }
                if (x == -1 && y == -1) {
                    cout << "Yes" << '\n';
                    return;
                }
                int hh = ve[idx[k]].first, ww = ve[idx[k]].second;
                if ((mask >> k) & 1) swap(hh, ww);
                for (int ii = x; ii < x + hh; ii++) {
                    for (int jj = y; jj < y + ww; jj++) {
                        if (ii >= h || ii < 0 || jj >= w || jj < 0) {
                            cant = true;
                            break;
                        }
                        if (isi[ii][jj]) {
                            cant = true;
                            break;
                        }
                        isi[ii][jj] = true;
                    }
                }
                if (cant) break;
            }
            int cek = 0;
            for (int ii = 0; ii < h; ii++) {
                for (int jj = 0; jj < w; jj++) {
                    cek += isi[ii][jj];
                }
            }
            if ((cek == h * w) && (!cant)) {
                cout << "Yes" << '\n';
                return;
            }
        }
    } while (next_permutation(idx.begin(), idx.end()));
    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}