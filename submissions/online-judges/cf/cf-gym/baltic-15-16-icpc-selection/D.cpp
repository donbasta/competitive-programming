#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve () {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(m, vector<bool>(n));
    vector<vector<ll>> dis(m, vector<ll>(n, INF));
    q.emplace(0, 0);
    vis[0][0] = true;
    dis[0][0] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto fr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = fr.first + dx[i];
            int ny = fr.second + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            if (s[nx][ny] == '#') {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            vis[nx][ny] = true;
            ll cost = (((nx + ny) & 1) ? b : a);
            dis[nx][ny] = min(dis[nx][ny], dis[fr.first][fr.second] + cost);
            q.emplace(nx, ny);
        }
    }
    if (dis[m - 1][n - 1] == INF) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dis[m - 1][n - 1] << '\n';
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}