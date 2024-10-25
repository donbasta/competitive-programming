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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();

    string cs = s;
    for (auto &c : cs) {
        if (c == '?') c = '1';
    }
    vector<ll> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (cs[i] != '0') dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (stoi(cs.substr(i - 1, 2)) <= 26 && cs[i - 1] != '0') {
            dp[i] = (dp[i] + (i >= 2 ? dp[i - 2] : 1)) % MOD;
        }
    }
    // debug(dp);
    vector<int> ve, pos;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '?') {
            if (s[i + 1] != '?') {
                if (s[i + 1] >= '7') {
                    ve.emplace_back(1);
                } else {
                    ve.emplace_back(2);
                }
            } else {
                ve.emplace_back(2);
            }
            pos.emplace_back(i);
        }
    }
    bool lmao = false;
    if (s.back() == '?') {
        if (s[n - 2] == '?') {
            ve.pop_back();
            pos.pop_back();
            ve.emplace_back(15);
            pos.emplace_back(-1);
        } else if (s[n - 2] == '2') {
            ve.emplace_back(6);
            pos.emplace_back(n - 1);
        } else {
            ve.emplace_back(9);
            pos.emplace_back(n - 1);
        }
    }
    --k;
    int sz = ve.size();
    vector<int> ord;
    for (int i = sz - 1; i >= 0; i--) {
        ord.push_back(ve[i] - 1 - (k % ve[i]));
        k /= ve[i];
    }
    reverse(ord.begin(), ord.end());
    // debug(ord);
    // debug(ve);
    string mp[] = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "21", "22", "23", "24", "25", "26"};
    for (int i = 0; i < sz; i++) {
        if (pos[i] == -1) {
            // cout << ord[i] << '\n';
            s[n - 2] = mp[ord[i]][0];
            s[n - 1] = mp[ord[i]][1];
            // s.substr(n - 2, 2) = mp[ord[i]];
        } else {
            s[pos[i]] = (char)(ord[i] + '1');
        }
    }
    cout << s << ' ' << dp.back() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        el_psy_congroo();
    }

    return 0;
}