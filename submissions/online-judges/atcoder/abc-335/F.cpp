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
const ll MOD = 998244353;

const int B = 100;
const int N = 2e5;

vector<ll> ve[B + 1];
ll ar[N + 1], base[N + 1], DP[N + 1];

void el_psy_congroo() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 1; i < B; i++) {
        ve[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            DP[i] = 1;
        } else {
            DP[i] = base[i];
            for (int j = 1; j < B; j++) {
                DP[i] = (DP[i] + ve[j][i]) % MOD;
            }
        }
        if (i < n - 1) {
            if (ar[i] >= B) {
                for (int j = i + ar[i]; j < n; j += ar[i]) {
                    base[j] = (base[j] + DP[i]) % MOD;
                }
            } else {
                int st = i + ar[i];
                int x = (n - 1 - i) / ar[i];
                int en = i + x * ar[i];
                int gap = ar[i], res = i % ar[i];
                for (int j = st / gap; j <= en / gap; j++) {
                    ve[gap][res][j] = (ve[gap][res][j] + DP[i]) % MOD;
                }
            }
        }
    }

    ll ans = 1;
    for (int i = 1; i < n; i++) {
        ans = (ans + DP[i]) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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