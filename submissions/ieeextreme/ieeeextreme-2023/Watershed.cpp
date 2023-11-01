#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ve(n, vector<int>(m));
    vector<vector<ld>> cap(n, vector<ld>(m, 1.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ve[i][j];
        }
    }
    vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));
    vector<vector<int>> in(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k].first, nj = j + dir[k].second;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (ve[ni][nj] >= ve[i][j]) continue;
                adj[i][j].emplace_back(ni, nj);
                in[ni][nj]++;
            }
        }
    }
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (in[i][j] == 0) {
                Q.emplace(i, j);
            }
        }
    }
    ld ans = 0;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        int flow_to = adj[now.first][now.second].size();
        if (flow_to == 0) {
            ans = max(ans, cap[now.first][now.second]);
            continue;
        }
        ld move = (ld)cap[now.first][now.second] / (ld)flow_to;
        for (auto nei : adj[now.first][now.second]) {
            cap[nei.first][nei.second] += move;
            in[nei.first][nei.second]--;
            if (in[nei.first][nei.second] == 0) {
                Q.emplace(nei);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
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