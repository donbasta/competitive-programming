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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> DP(n), PD(n), highest_leaf_depth(n, INF);
    const function<void(int, int, int)> dfs = [&](int v, int p, int dep) {
        ll tmp = 0;
        ll sum = 0;
        ll chd = 0;
        for (auto c : adj[v]) {
            if (c == p) continue;
            chd++;
            dfs(c, v, dep + 1);
            highest_leaf_depth[v] = min(highest_leaf_depth[v], highest_leaf_depth[c]);
            DP[v] = max(DP[v], DP[c]);
            PD[v] += PD[c];
            sum += PD[c];
            tmp = max(tmp, DP[c] - PD[c]);
        }
        if (chd == 0) {
            highest_leaf_depth[v] = dep;
            DP[v] = 1;
            PD[v] = 1;
        } else {
            DP[v] = max(DP[v], tmp + sum);
            if (highest_leaf_depth[v] >= dep + k) {
                PD[v] = 0;
            }
        }
    };
    dfs(0, 0, 0);
    cout << DP[0] << '\n';
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