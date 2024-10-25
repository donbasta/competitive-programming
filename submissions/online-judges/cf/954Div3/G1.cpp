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
const int MX = 5e5;
vector<int> divs[MX + 5];

void init() {
    for (int j = 1; j <= MX; j++) {
        for (int k = j; k <= MX; k += j) {
            divs[k].push_back(j);
        }
    }
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) {
        int d = __gcd(i, ar[i]);
        debug(i, i / d, ar[i] / d);
        A[i / d].push_back(ar[i] / d);
        B[ar[i] / d].push_back(i / d);
    }
    ll ans = 0;

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto a : A[i]) {
            for (auto d : divs[a]) {
                cnt[d]++;
            }
        }
        debug(i, cnt);
        for (int j = i; j <= n; j += i) {
            for (auto a : B[j]) {
                ans += cnt[a];
            }
        }
        for (auto a : A[i]) {
            for (auto d : divs[a]) {
                cnt[d]--;
            }
        }
        debug(i, ans);
    }

    ans -= n;

    // for (int i = 0; i < n; i++) {
    //     int a = ve[i].first, b = ve[i].second;
    //     for (auto d : divs[a]) {
    //         cnt[b][d]++;
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     int a = ve[i].first, b = ve[i].second;
    //     for (auto d : divs[a]) {
    //         ans += cnt[d][b];
    //     }
    // }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}