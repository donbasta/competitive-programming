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
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<pair<int, int>> mn(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[ar[i]].push_back(i);
    }
    mn[0] = make_pair(ar[0], 0);
    for (int i = 1; i < n; i++) {
        if (ar[i] < mn[i - 1].first) {
            mn[i] = make_pair(ar[i], i);
        } else {
            mn[i] = mn[i - 1];
        }
    }

    vector<ll> dp(n, -1);
    const function<ll(ll, ll)> solve = [&](ll r, ll height) -> ll {
        if (r < 0) return 0;
        if (dp[r] != -1) {
            return dp[r];
        }
        pair<int, int> T = mn[r];
        int mn = T.first, idx = T.second;
        ll tmp = mn - height;
        ll cnt = upper_bound(mp[mn].begin(), mp[mn].end(), r) - lower_bound(mp[mn].begin(), mp[mn].end(), idx);
        tmp += (r - idx + 1) - cnt;
        tmp += solve(idx - 1, mn);
        debug(r, tmp);
        return dp[r] = min(r + 1, tmp);
    };

    cout << solve(n - 1, 0) << '\n';
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