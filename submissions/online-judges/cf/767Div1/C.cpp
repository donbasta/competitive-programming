#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < (n / 2); i++) {
        vector<pair<int, int>> cyc;
        int cx = 2 * i, cy = 2 * i;
        while (cx < n - 1 - 2 * i) {
            cyc.emplace_back(cx, cy);
            cx++;
        }
        while (cy < n - 1 - 2 * i) {
            cyc.emplace_back(cx, cy);
            cy++;
        }
        while (cx > 2 * i) {
            cyc.emplace_back(cx, cy);
            cx--;
        }
        while (cy > 2 * i) {
            cyc.emplace_back(cx, cy);
            cy--;
        }
        assert(cyc.size() % 4 == 0);
        for (int j = 0; j < cyc.size(); j += 4) {
            int xx = cyc[j].first, yy = cyc[j].second;
            ans ^= adj[xx][yy];
            ans ^= adj[n - 1 - xx][yy];
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