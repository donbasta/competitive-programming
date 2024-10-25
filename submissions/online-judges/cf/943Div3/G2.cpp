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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void el_psy_congroo() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    // divide jadi r bagian, berapa LCPnya?

    // RollingHash rh(s);
    vector<int> z = z_function(s);

    int bat = ceil(sqrt(n));
    vector<int> ret(n + 1);

    for (int i = 1; i <= bat; i++) {
        int lo = 1, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = 0;

            for (int i = mid; i < n;) {
                if (z[i] >= mid) {
                    cnt++;
                    i += mid;
                } else {
                    i++;
                }
            }

            if (cnt >= i - 1) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ret[i] = ans;
    }
    for (int len = 1; len <= bat; len++) {
        int k = 1;
        for (int i = len; i < n;) {
            if (z[i] >= len) {
                k++;
                i += len;
            } else {
                i++;
            }
        }

        ret[k] = max(ret[k], len);
    }
    for (int i = n - 1; i >= 1; i--) {
        ret[i] = max(ret[i], ret[i + 1]);
    }

    for (int i = l; i <= r; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
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