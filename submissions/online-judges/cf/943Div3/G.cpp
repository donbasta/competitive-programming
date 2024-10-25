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

int fpow(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ret;
}

struct RollingHash {
    const vector<int> B = {31, 41};
    const vector<int> M = {1000000007, 998244353};
    vector<int> H[2], pw[2], ipw[2];
    int iB[2];
    RollingHash(const string &s) {
        int n = s.length();
        H[0].resize(n), H[1].resize(n);
        pw[0].resize(n + 1), pw[1].resize(n + 1);
        ipw[0].resize(n + 1), ipw[1].resize(n + 1);
        pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
        for (int i = 0; i < 2; i++) {
            iB[i] = fpow(B[i], M[i] - 2, M[i]);
            for (int j = 1; j <= n; j++) {
                pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
                ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
            }
            H[i][0] = (s[0] - 'a' + 1);
            for (int j = 1; j < n; j++) {
                H[i][j] = (1ll * H[i][j - 1] + 1ll * (s[j] - 'a' + 1) * pw[i][j]) % M[i];
            }
        }
    }
    pair<int, int> get_hash(int a, int b) {
        vector<int> X(2);
        for (int i = 0; i < 2; i++) {
            int hsh = (H[i][b] - (a ? H[i][a - 1] : 0)) % M[i];
            if (hsh < 0) hsh += M[i];
            hsh = (1ll * hsh * ipw[i][a]) % M[i];
            X[i] = hsh;
        }
        return make_pair(X[0], X[1]);
    }
    pair<int, int> go_hash(const string &S) {
        vector<int> X(2);
        int n = S.length();
        for (int i = 0; i < 2; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp = (1ll * tmp + 1ll * (S[j] - 'a' + 1) * pw[i][j]) % M[i];
            }
            X[i] = tmp;
        }
        return make_pair(X[0], X[1]);
    }
};

void el_psy_congroo() {
    int n, l, r;
    cin >> n >> l >> r;
    assert(l == r);
    string s;
    cin >> s;
    // divide jadi r bagian, berapa LCPnya?
    int lo = 1, hi = n, ans = 0;

    RollingHash rh(s);
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int cnt = 0;
        pair<int, int> cek = rh.get_hash(0, mid - 1);

        int ptr = 2 * mid - 1;
        while (ptr < n) {
            if (cek == rh.get_hash(ptr - mid + 1, ptr)) {
                cnt++;
                ptr += mid;
            } else {
                ptr++;
            }
        }

        if (cnt >= r - 1) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
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