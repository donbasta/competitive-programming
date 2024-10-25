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
const int M = 2e5;

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) {
            return;
        }
        par[x] = y;
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    vector<vector<int>> from(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    DSU dsu(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (ar[u] == ar[v]) {
            dsu.merge(u, v);
        } else {
            edges.emplace_back(u, v);
        }
    }

    vector<int> val(n, -1), in(n);
    for (auto e : edges) {
        int u = e.first, v = e.second;
        assert(ar[u] != ar[v]);
        if (ar[u] < ar[v]) {
            from[dsu.fpar(u)].push_back(dsu.fpar(v));
        } else if (ar[u] > ar[v]) {
            from[dsu.fpar(v)].push_back(dsu.fpar(u));
        }
    }

    vector<bool> vis(n);
    queue<int> R;
    vis[dsu.fpar(0)] = true;
    R.push(dsu.fpar(0));
    while (!R.empty()) {
        auto now = R.front();
        R.pop();
        for (auto c : from[now]) {
            if (vis[c]) continue;
            vis[c] = true;
            R.push(c);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) continue;
        for (auto c : from[i]) {
            in[c]++;
        }
    }

    queue<int> Q;
    val[dsu.fpar(0)] = 1;
    Q.push(dsu.fpar(0));
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : from[now]) {
            val[c] = max(val[c], val[now] + 1);
            --in[c];
            if (in[c] == 0) {
                Q.push(c);
            }
        }
    }

    if (val[dsu.fpar(n - 1)] == -1) {
        cout << 0 << '\n';
        return;
    }
    cout << val[dsu.fpar(n - 1)] << '\n';
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