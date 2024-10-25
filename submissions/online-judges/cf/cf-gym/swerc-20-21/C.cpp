#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int x, y;
    cin >> x >> y;
    ld lx = x, ly = y;
    int n;
    cin >> n;
    vector<ld> pts[n];
    ld d[n][n];
    for (int i = 0; i < n; i++) {
        pts[i].resize(2);
        cin >> pts[i][0] >> pts[i][1];
    }

    auto get_dis = [&](const vector<ld>& A, vector<ld>& B) -> ld {
        ld dx = A[0] - B[0];
        ld dy = A[1] - B[1];
        ld sq = dx * dx + dy * dy;
        return sqrtl(sq);
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            d[i][j] = d[j][i] = get_dis(pts[i], pts[j]);
        }
    }
    ld l = 0, r = lx + ly;
    while (r - l > 1e-9) {
        ld mid = (l + r) / 2;
        vector<int> adj[n + 4];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (d[i][j] < mid * 2) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if ((lx - pts[i][0]) < mid) adj[i].push_back(n), adj[n].push_back(i);
            if (pts[i][0] < mid) adj[i].push_back(n + 1), adj[n + 1].push_back(i);
            if ((ly - pts[i][1]) < mid) adj[i].push_back(n + 2), adj[n + 2].push_back(i);
            if (pts[i][1] < mid) adj[i].push_back(n + 3), adj[n + 3].push_back(i);
        }
        bool vis[n + 4];
        bool ok = true;
        queue<int> Q;

        memset(vis, 0, sizeof(vis));
        Q.emplace(n);
        vis[n] = true;
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.emplace(c);
            }
        }
        if (vis[n + 2] || vis[n + 1]) {
            ok = false;
        }

        memset(vis, 0, sizeof(vis));
        Q.emplace(n + 2);
        vis[n + 2] = true;
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.emplace(c);
            }
        }
        if (vis[n] || vis[n + 3]) {
            ok = false;
        }

        memset(vis, 0, sizeof(vis));
        Q.emplace(n + 1);
        vis[n + 1] = true;
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.emplace(c);
            }
        }
        if (vis[n + 3] || vis[n]) {
            ok = false;
        }

        memset(vis, 0, sizeof(vis));
        Q.emplace(n + 3);
        vis[n + 3] = true;
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.emplace(c);
            }
        }
        if (vis[n + 1] || vis[n + 2]) {
            ok = false;
        }

        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(10) << l << '\n';
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