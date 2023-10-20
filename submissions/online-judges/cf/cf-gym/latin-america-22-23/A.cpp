#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[i].push_back(x);
        adj[i].push_back(y);
    }
    string s(n, 'N');

    vector<int> cnt(n);
    vector<vector<int>> tmp(n);
    const function<void(int)> go = [&](int start) {
        vector<bool> vis(n);
        queue<int> Q;
        Q.push(start);
        vis[start] = true;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : tmp[now]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.push(c);
            }
        }
        for (int i = 0; i < n; i++) {
            cnt[i] += (vis[i]);
        }
    };

    for (int i = 0; i < n; i++) {
        fill(cnt.begin(), cnt.end(), 0);
        tmp.clear();
        tmp.resize(n);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            tmp[adj[j][0]].push_back(j);
            tmp[adj[j][1]].push_back(j);
        }
        go(i);
        go(adj[i][0]);
        go(adj[i][1]);

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (cnt[j] == 3) {
                s[i] = 'Y';
                break;
            }
        }
    }
    cout << s << '\n';
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