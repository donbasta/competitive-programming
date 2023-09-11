#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> rw(n), cl(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rw[i] += (s[i][j] != '.');
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cl[i] += (s[j][i] != '.');
        }
    }
    for (int i = 0; i < n; i++) {
        if (rw[i] & 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (cl[i] & 1) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<string> ret(n, string(m, '.'));
    vector<vector<int>> col(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> adj(m * n);
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') tmp.push_back(i * m + j);
        }
        for (int k = 1; k < (int)tmp.size(); k++) {
            adj[tmp[k]].push_back(tmp[k - 1]);
            adj[tmp[k - 1]].push_back(tmp[k]);
        }
    }
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (s[j][i] != '.') tmp.push_back(j * m + i);
        }
        for (int k = 1; k < (int)tmp.size(); k++) {
            adj[tmp[k]].push_back(tmp[k - 1]);
            adj[tmp[k - 1]].push_back(tmp[k]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            queue<pair<int, int>> Q;
            col[i][j] = 0;
            Q.push(make_pair(i, j));
            while (!Q.empty()) {
                auto now = Q.front();
                int ni = now.first, nj = now.second;
                Q.pop();
                pair<int, int> neighbor;
                if (s[ni][nj] == 'L') neighbor = make_pair(ni, nj + 1);
                if (s[ni][nj] == 'R') neighbor = make_pair(ni, nj - 1);
                if (s[ni][nj] == 'U') neighbor = make_pair(ni + 1, nj);
                if (s[ni][nj] == 'D') neighbor = make_pair(ni - 1, nj);
                vis[neighbor.first][neighbor.second] = true;
                col[neighbor.first][neighbor.second] = col[ni][nj] ^ 1;
                for (auto c : adj[ni * m + nj]) {
                    if (vis[c / m][c % m]) continue;
                    vis[c / m][c % m] = true;
                    col[c / m][c % m] = col[ni][nj] ^ 1;
                    Q.push(make_pair(c / m, c % m));
                }
                for (auto c : adj[neighbor.first * m + neighbor.second]) {
                    if (vis[c / m][c % m]) continue;
                    vis[c / m][c % m] = true;
                    col[c / m][c % m] = col[ni][nj];
                    Q.push(make_pair(c / m, c % m));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;
            if (col[i][j])
                ret[i][j] = 'B';
            else
                ret[i][j] = 'W';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}