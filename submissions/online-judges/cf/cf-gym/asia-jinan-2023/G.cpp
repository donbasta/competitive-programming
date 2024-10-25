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

void el_psy_congroo() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    if ((c & 1)) {
        int cnt_mid = 0;
        for (int j = 0; j < r; j++) cnt_mid += (grid[j][c / 2] == '1');
        if (cnt_mid > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    vector<vector<pair<int, int>>> adj(r);
    vector<int> vis(r, -1);
    for (int i = 0; i < c / 2; i++) {
        vector<int> A, B;
        for (int j = 0; j < r; j++) {
            if (grid[j][i] == '1') A.push_back(j);
            if (grid[j][c - 1 - i] == '1') B.push_back(j);
        }
        if (A.size() + B.size() >= 3) {
            cout << 0 << '\n';
            return;
        }
        if (A.size() == 1 && B.size() == 1) {
            adj[A[0]].emplace_back(B[0], 0);
            adj[B[0]].emplace_back(A[0], 0);
        } else if (max(A.size(), B.size()) == 2) {
            if (A.size() == 2) {
                adj[A[0]].emplace_back(A[1], 1);
                adj[A[1]].emplace_back(A[0], 1);
            } else if (B.size() == 2) {
                adj[B[0]].emplace_back(B[1], 1);
                adj[B[1]].emplace_back(B[0], 1);
            }
        }
    }

    const function<bool(int)> dfs = [&](int v) -> bool {
        for (auto c : adj[v]) {
            if (vis[c.first] != -1) {
                if (vis[v] ^ c.second != vis[c.first]) {
                    return false;
                } else {
                    continue;
                }
            }
            vis[c.first] = vis[v] ^ c.second;
            if (!dfs(c.first)) {
                return false;
            }
        }
        return true;
    };

    bool ok = false;
    ll ans = 1;
    for (int i = 0; i < r; i++) {
        if (vis[i] == -1) {
            ok = true;
            vis[i] = 0;
            if (!dfs(i)) {
                cout << 0 << '\n';
                return;
            }
            ans = (ans * 2) % MOD;
        }
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