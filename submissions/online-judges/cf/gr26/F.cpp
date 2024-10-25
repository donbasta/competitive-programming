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

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int cp = count(s.begin(), s.end(), 'P');
    int cs = count(s.begin(), s.end(), 'S');
    int cq = count(s.begin(), s.end(), '?');
    ll ans = 0;
    bool okA = false, okB = false;
    if (cs == 0) {
        okA = abs(B[0]) <= m;
        for (int i = 1; i < n; i++) {
            okA &= abs(B[i] - B[i - 1]) <= m;
        }
    }
    if (cp == 0) {
        okB = abs(B.back()) <= m;
        for (int i = 1; i < n; i++) {
            okB &= abs(B[i] - B[i - 1]) <= m;
        }
    }
    set<ll> se, tmp;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'P' && s[i + 1] == 'S') {
            tmp.insert(B[i] + B[i + 1]);
        }
    }
    if (tmp.size() > 1) {
        cout << 0 << '\n';
        return;
    }
    if (tmp.size() == 0) {
        for (int i = 0; i < n - 1; i++) {
            se.insert(B[i] + B[i + 1]);
        }
    } else {
        se.insert(*tmp.begin());
    }

    for (auto sum : se) {
        if (abs(sum) > m * n) continue;
        vector<vector<ll>> DP(n, vector<ll>(2));
        if (s[0] == 'P') {
            if (abs(B[0]) > m) {
                continue;
            }
            DP[0][0] = 1;
        } else if (s[0] == 'S') {
            if (B[0] != sum) continue;
            DP[0][1] = 1;
        } else if (s[0] == '?') {
            int cnt = 0;
            if (abs(B[0]) <= m) {
                DP[0][0] = 1;
                cnt++;
            }
            if (B[0] == sum) {
                DP[0][1] = 1;
                cnt++;
            }
            if (cnt == 0) continue;
        }
        for (int j = 1; j < n; j++) {
            if (s[j] == 'P') {
                int cnt = 0;
                if (abs(B[j] + B[j - 1] - sum) <= m * 2) {
                    cnt++;
                    DP[j][0] = (DP[j][0] + DP[j - 1][1]) % MOD;
                }
                if (abs(B[j] - B[j - 1]) <= m) {
                    cnt++;
                    DP[j][0] = (DP[j][0] + DP[j - 1][0]) % MOD;
                }
                if (cnt == 0) {
                    break;
                }
            } else if (s[j] == 'S') {
                int cnt = 0;
                if (B[j] + B[j - 1] == sum) {
                    cnt++;
                    DP[j][1] = (DP[j][1] + DP[j - 1][0]) % MOD;
                }
                if (abs(B[j] - B[j - 1]) <= m) {
                    cnt++;
                    DP[j][1] = (DP[j][1] + DP[j - 1][1]) % MOD;
                }
                if (cnt == 0) {
                    break;
                }
            } else if (s[j] == '?') {
                int cnt = 0;
                if (abs(B[j] + B[j - 1] - sum) <= m * 2) {
                    cnt++;
                    DP[j][0] = (DP[j][0] + DP[j - 1][1]) % MOD;
                }
                if (abs(B[j] - B[j - 1]) <= m) {
                    cnt++;
                    DP[j][0] = (DP[j][0] + DP[j - 1][0]) % MOD;
                }
                if (B[j] + B[j - 1] == sum) {
                    cnt++;
                    // debug(sum, j);
                    DP[j][1] = (DP[j][1] + DP[j - 1][0]) % MOD;
                }
                if (abs(B[j] - B[j - 1]) <= m) {
                    cnt++;
                    DP[j][1] = (DP[j][1] + DP[j - 1][1]) % MOD;
                }
                if (cnt == 0) {
                    break;
                }
            }
        }
        // debug(DP[0]);
        // debug(DP[1]);
        // debug(DP[2]);
        ans = (ans + DP[n - 1][0]) % MOD;
        ans = (ans + DP[n - 1][1]) % MOD;
    }
    if (okA && (!se.count(B.back()))) {
        ans = (ans + 1) % MOD;
    }
    if (okB && (!se.count(B[0]))) {
        ans = (ans + 1) % MOD;
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