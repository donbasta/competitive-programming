#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int B = 19;

vector<int> cand[B + 1];
int lamp[B + 1][B + 1];

void init() {
    for (int i = 1; i <= B; i++) {
        for (int j = 1; j < (1 << i); j++) {
            int on = __builtin_popcount(j);
            if (on <= (i / 5)) cand[i].push_back(j);
        }
        for (int j = 0; j < i; j++) {
            int mask = 0;
            for (int k = j; k < i; k += (j + 1)) {
                mask ^= (1 << k);
            }
            lamp[i][j] = mask;
        }
    }
}

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }
    if (n > B) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (auto c : cand[n]) {
        bool ok = true;
        int mask = 0;
        vector<int> on(n);
        for (int i = 0; i < n; i++) {
            if (((mask >> i) & 1) != ((c >> i) & 1)) {
                mask ^= lamp[n][i];
                on[i] = true;
            }
        }
        for (auto e : edges) {
            if (on[e.first] && !on[e.second]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            vector<int> ret;
            for (int i = 0; i < n; i++) {
                if (on[i]) ret.push_back(i);
            }
            cout << ret.size() << '\n';
            for (auto e : ret) cout << (e + 1) << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}