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

pair<int, int> dir[] = {
    {1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;

    unordered_map<ll, int> mp;
    vector<pair<int, int>> ve;
    int idx = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        mp[x * n + y] = idx++;
        ve.emplace_back(x, y);
    }
    assert(idx == m);
    vector<vector<int>> adj(m + 4);
    // m, m+1, m+2, m+3 for U, R, D, L
    for (int i = 0; i < m; i++) {
        int cx = ve[i].first, cy = ve[i].second;
        for (int j = 0; j < 8; j++) {
            int nx = cx + dir[j].first, ny = cy + dir[j].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (mp.find(nx * n + ny) == mp.end()) continue;
            adj[i].push_back(mp[nx * n + ny]);
        }
        if (cx == 0) {
            adj[i].push_back(m), adj[m].push_back(i);
        }
        if (cx == n - 1) {
            adj[i].push_back(m + 2), adj[m + 2].push_back(i);
        }
        if (cy == 0) {
            adj[i].push_back(m + 3), adj[m + 3].push_back(i);
        }
        if (cy == n - 1) {
            adj[i].push_back(m + 1), adj[m + 1].push_back(i);
        }
    }

    queue<int> Q;
    vector<bool> vis(m + 4);
    vis[m] = vis[m + 1] = true;
    Q.push(m);
    Q.push(m + 1);
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : adj[now]) {
            if (vis[c]) continue;
            vis[c] = true;
            Q.push(c);
        }
    }
    if (vis[m + 2] || vis[m + 3]) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
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