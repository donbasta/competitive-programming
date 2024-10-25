#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    int cc = 0;
    vector<vector<int>> par(h, vector<int>(w, -1));
    vector<vector<bool>> vis(h, vector<bool>(w));

    pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const function<void(int, int)> ff = [&](int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (grid[nx][ny] == '.') continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            par[nx][ny] = cc;
            ff(nx, ny);
        }
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '.') continue;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            par[i][j] = cc;
            ff(i, j);
            cc++;
        }
    }

    ll tot = 0, cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') continue;
            set<int> se;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k].first, nj = j + dir[k].second;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (grid[ni][nj] == '.') continue;
                se.insert(par[ni][nj]);
            }
            ll nc;
            if (se.size() >= 1) {
                nc = cc - (se.size() - 1);
            } else if (se.size() == 0) {
                nc = cc + 1;
            }
            tot = (tot + nc) % MOD;
            cnt++;
        }
    }
    tot = (tot * fpow(cnt, MOD - 2)) % MOD;
    if (tot < 0) tot += MOD;
    cout << tot << '\n';
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