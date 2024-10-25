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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> W(n), A(n);
    for (int i = 0; i < n; i++) cin >> W[i];
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
        return W[a] < W[b];
    });
    vector<ll> DP(n, 1);
    for (int i = 0; i < n; i++) {
        // process idx[i];
        ll cur_w = W[idx[i]];
        vector<pair<ll, int>> cont;
        for (auto ne : adj[idx[i]]) {
            if (W[ne] < cur_w) {
                cont.emplace_back(W[ne], ne);
            }
        }
        int sz = cont.size();
        if (sz == 0) {
            continue;
        }
        // debug(idx[i], cont);

        vector<vector<ll>> dp(sz, vector<ll>(cur_w, -1));
        dp[0][0] = 0, dp[0][cont[0].first] = DP[cont[0].second];
        for (int j = 1; j < sz; j++) {
            for (int k = 0; k < cur_w; k++) {
                dp[j][k] = dp[j - 1][k];
            }
            for (int k = cont[j].first; k < cur_w; k++) {
                if (dp[j - 1][k - cont[j].first] != -1) {
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - cont[j].first] + DP[cont[j].second]);
                }
            }
        }
        // debug(idx[i], dp[sz - 1]);

        for (int j = 0; j < cur_w; j++) {
            if (dp[sz - 1][j] != -1) {
                DP[idx[i]] = max(DP[idx[i]], 1 + dp[sz - 1][j]);
            }
        }
    }
    debug(DP);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += DP[i] * A[i];
    }
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