#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

pair<int, int> dir[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void el_psy_congroo() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    int ans = 0;

    vector<vector<bool>> vis(h, vector<bool>(w));
    const function<void(int, int)> ff = [&](int x, int y) {
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (s[nx][ny] == '.') continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            ff(nx, ny);
        }
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') continue;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            ff(i, j);
            ans++;
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
        el_psy_congroo();
    }

    return 0;
}