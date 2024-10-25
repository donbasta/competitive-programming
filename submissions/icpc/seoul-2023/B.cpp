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

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int v, int val) {
        v++;
        while (v <= n) {
            tree[v] += val;
            v += v & -v;
        }
    }
    int get(int v) {
        v++;
        int ret = 0;
        while (v > 0) {
            ret += tree[v];
            v -= v & -v;
        }
        return ret;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> apple(n);
    for (int i = 0; i < n; i++) {
        cin >> apple[i];
    }
    swap(apple[0], apple[apple.back() % (n - 1)]);

    BIT bit(n);
    for (int i = 0; i < n; i++) bit.upd(i, 1);

    vector<int> ret(n);
    int cur = 0;
    bit.upd(0, -1);
    ret[0] = apple[0];
    int rem = n - 1;

    for (int i = 1; i < n; i++) {
        int tam = apple[i - 1] % rem;
        if (tam == 0) tam = rem;
        int kanan = bit.get(cur + 1, n - 1);
        // debug(i, tam, kanan);
        if (kanan < tam) {
            tam -= kanan;
            // binser di kiri
            int L = 0, R = cur - 1, nx = -1;
            while (L <= R) {
                int M = (L + R) >> 1;
                if (bit.get(0, M) < tam) {
                    L = M + 1;
                } else {
                    nx = M;
                    R = M - 1;
                }
            }
            cur = nx;
        } else {
            // binser di kanan
            int L = cur + 1, R = n - 1, nx = -1;
            while (L <= R) {
                int M = (L + R) >> 1;
                if (bit.get(cur + 1, M) < tam) {
                    L = M + 1;
                } else {
                    nx = M;
                    R = M - 1;
                }
            }
            cur = nx;
        }
        // debug(i, cur);
        bit.upd(cur, -1);
        ret[cur] = apple[i];
        rem--;
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i] << '\n';
    }
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