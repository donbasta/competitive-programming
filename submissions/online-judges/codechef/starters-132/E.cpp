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

const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> ar(n);

    ll tot = 0;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tot += k;
        ar[i].resize(k);

        for (int j = 0; j < k; j++) {
            cin >> ar[i][j];
            mp[-ar[i][j]].push_back(i);
        }
    }

    ll cnt_all = 0, val = 0, ans = 0, sum_all = 0;
    vector<ll> cnt(n), sum(n);
    for (auto x : mp) {
        int val = -x.first;
        vector<ll> exps;
        for (auto idx : x.second) {
            if (cnt_all == 0) {
                ans = (ans + val) % MOD;
                exps.push_back(val);
                // debug(val, val, idx);
            } else {
                cnt_all -= cnt[idx];
                sum_all = (sum_all - sum[idx]) % MOD;
                ll exp = (val + sum_all * inv(cnt_all)) % MOD;
                // debug(val, exp, idx, sum_all, cnt_all);
                ans = (ans + exp) % MOD;
                exps.push_back(exp);
                cnt_all += cnt[idx];
                sum_all = (sum_all + sum[idx]) % MOD;
            }
        }
        int sz = x.second.size();
        for (int i = 0; i < sz; i++) {
            int idx = x.second[i], exp_val = exps[i];
            cnt[idx]++, sum[idx] = (sum[idx] + exp_val) % MOD;
            cnt_all++, sum_all = (sum_all + exp_val) % MOD;
        }
    }
    // debug(ans);

    ans = (ans * inv(tot)) % MOD;
    ans %= MOD;
    if (ans < 0) ans += MOD;
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