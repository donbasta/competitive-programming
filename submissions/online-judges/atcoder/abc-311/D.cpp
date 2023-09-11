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
    queue<pair<int, int>> Q;
    vector<vector<bool>> start_from(n, vector<bool>(m));
    vector<vector<bool>> can_visit(n, vector<bool>(m));
    Q.emplace(1, 1);
    start_from[1][1] = true;
    can_visit[1][1] = true;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = dir[i].first, dy = dir[i].second;
            int cx = now.first, cy = now.second;
            while (s[cx][cy] == '.') {
                can_visit[cx][cy] = true;
                cx += dx, cy += dy;
            }
            cx -= dx, cy -= dy;
            if (!start_from[cx][cy]) {
                Q.emplace(cx, cy);
                start_from[cx][cy] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += can_visit[i][j];
        }
    }
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