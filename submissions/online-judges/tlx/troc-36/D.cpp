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
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    queue<int> Q;
    Q.push(0);
    vector<int> par(n, -1), vis(n, 0);
    vis[0] = true;
    bool cyc_found = false;
    int s1 = -1, s2 = -1;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : adj[now]) {
            if (c == par[now]) continue;
            if (vis[c]) {
                s1 = now, s2 = c;
                cyc_found = true;
                break;
            }
            par[c] = now;
            vis[c] = true;
            Q.push(c);
        }
        if (cyc_found) break;
    }

    vector<int> A, B;
    int cur = s1;
    while (cur != 0) {
        A.push_back(cur);
        cur = par[cur];
    }
    A.push_back(0);
    cur = s2;
    while (cur != 0) {
        B.push_back(cur);
        cur = par[cur];
    }
    B.push_back(0);
    int lca = -1;
    while (A.back() == B.back()) {
        lca = A.back();
        A.pop_back(), B.pop_back();
    }
    A.push_back(lca);
    reverse(B.begin(), B.end());
    for (auto b : B) A.push_back(b);

    int max_deg = 0;
    int mn = INT_MAX;
    vector<bool> in_cyc(n);
    for (auto a : A) {
        in_cyc[a] = true;
        mn = min(mn, deg[a] - 2);
        max_deg += deg[a] - 2;
    }
    max_deg -= mn;
    max_deg++;

    for (int i = 0; i < n; i++) {
        if (in_cyc[i]) continue;
        max_deg = max(max_deg, deg[i]);
    }
    int ans = (n - 1 - max_deg);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}