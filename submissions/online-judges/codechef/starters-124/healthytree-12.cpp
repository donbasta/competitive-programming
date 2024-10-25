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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> Q;
    bool udah1 = false, subtask2 = true, subtask1 = true;
    for (int i = 0; i < q; i++) {
        int tp, u;
        cin >> tp >> u;
        --u;
        if (tp == 2) {
            if (udah1) {
                subtask2 = false;
            }
        }
        if (tp == 1) {
            udah1 = true;
            if (u != 0) {
                subtask1 = false;
            }
        }
        Q.emplace_back(tp, u);
    }

    if (subtask2) {
        vector<int> que, occ(n);
        for (int i = 0; i < q; i++) {
            if (Q[i].first == 2) {
                occ[Q[i].second] ^= 1;
            } else {
                que.emplace_back(Q[i].second);
            }
        }
        vector<int> score(n);
        vector<deque<int>> ve(n);
        const function<void(int, int)> dfs = [&](int v, int p) {
            ve[v].push_back(occ[v]);
            int cur = occ[v];
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                if (ve[c].size() >= ve[v].size()) {
                    int add = score[c];
                    for (int j = 1; j < ve[v].size(); j++) {
                        if (ve[v][j] == 1) cur--;
                        if (ve[c][j - 1] == 1) add--;
                        ve[c][j - 1] += ve[v][j];
                        if (ve[c][j - 1] == 1) cur++;
                    }
                    ve[c].push_front(occ[v]);
                    ve[c].swap(ve[v]);
                    cur += add;
                } else {
                    for (int j = 0; j < ve[c].size(); j++) {
                        if (ve[v][j + 1] == 1) cur--;
                        ve[v][j + 1] += ve[c][j];
                        if (ve[v][j + 1] == 1) cur++;
                    }
                }
            }
            score[v] = cur;
        };
        dfs(0, 0);
        for (auto q : que) {
            cout << (score[q] - occ[q]) << '\n';
        }
    } else if (subtask1) {
        vector<set<int>> ve(n);
        vector<int> dep(n);
        const function<void(int, int, int)> dfs = [&](int v, int p, int d) {
            dep[v] = d;
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v, d + 1);
            }
        };
        dfs(0, 0, 0);
        int score = 0;

        for (int i = 0; i < q; i++) {
            if (Q[i].first == 1) {
                assert(Q[i].second == 0);
                cout << (score - (ve[0].size() == 1)) << '\n';
            } else if (Q[i].first == 2) {
                int u = Q[i].second;
                if (ve[dep[u]].size() == 1) score--;
                if (ve[dep[u]].count(u)) {
                    ve[dep[u]].erase(u);
                } else {
                    ve[dep[u]].insert(u);
                }
                if (ve[dep[u]].size() == 1) score++;
            }
        }
    } else {
        for (auto que : Q) {
            if (que.first == 1) {
                cout << 0 << '\n';
            }
        }
    }
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