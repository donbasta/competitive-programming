#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

ll n, m, w;
ll ans = INF;
vector<ll> pr[2];

const int N = 2e3;
bool vis[2][N + 5][N + 5];
ll ar[N + 5][N + 5], d[2][N + 5][N + 5];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m;
}

void ff(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    vis[id][x][y] = 1;
    if (ar[x][y] > 0) {
        pr[id].emplace_back(ar[x][y]);
    }
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (!valid(nx, ny)) continue;
            if (ar[nx][ny] == -1) continue;
            if (vis[id][nx][ny]) continue;
            vis[id][nx][ny] = 1;
            d[id][nx][ny] = d[id][xx][yy] + w;
            q.emplace(nx, ny);
            if (ar[nx][ny] > 0) {
                pr[id].emplace_back(d[id][nx][ny] + ar[nx][ny]);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    ff(0, 0, 0);
    if (vis[0][n - 1][m - 1]) {
        ans = d[0][n - 1][m - 1];
    }
    ff(n - 1, m - 1, 1);
    if (!pr[0].empty() && !pr[1].empty()) {
        sort(pr[0].begin(), pr[0].end());
        sort(pr[1].begin(), pr[1].end());
        ans = min(ans, pr[0][0] + pr[1][0]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}