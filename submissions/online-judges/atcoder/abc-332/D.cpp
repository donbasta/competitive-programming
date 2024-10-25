#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w)), B(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> B[i][j];
        }
    }
    vector<int> ph(h), pw(w);
    iota(ph.begin(), ph.end(), 0);
    iota(pw.begin(), pw.end(), 0);
    vector<vector<int>> hh, ww;
    do {
        hh.push_back(ph);
    } while (next_permutation(ph.begin(), ph.end()));
    do {
        ww.push_back(pw);
    } while (next_permutation(pw.begin(), pw.end()));
    map<vector<vector<int>>, int> id;
    vector<vector<vector<int>>> nodes;
    int T = 0;
    for (auto x : hh) {
        for (auto y : ww) {
            vector<vector<int>> tmp(h, vector<int>(w));
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    tmp[i][j] = A[x[i]][y[j]];
                }
            }
            id[tmp] = T++;
            nodes.push_back(tmp);
        }
    }
    if (!id.count(B)) {
        cout << -1 << '\n';
        return;
    }
    int sz = nodes.size();
    // cerr << sz << '\n';
    vector<vector<int>> adj(sz);
    for (auto node : nodes) {
        int cur = id[node];
        // cerr << cur << '\n';
        for (int i = 0; i < w - 1; i++) {
            int j = i + 1;
            for (int x = 0; x < h; x++) {
                swap(node[x][i], node[x][j]);
            }
            adj[cur].push_back(id[node]);
            for (int x = 0; x < h; x++) {
                swap(node[x][i], node[x][j]);
            }
        }
        for (int i = 0; i < h - 1; i++) {
            int j = i + 1;
            for (int x = 0; x < w; x++) {
                swap(node[i][x], node[j][x]);
            }
            adj[cur].push_back(id[node]);
            for (int x = 0; x < w; x++) {
                swap(node[i][x], node[j][x]);
            }
        }
    }
    // cerr << "tes" << '\n';

    vector<bool> vis(sz);
    vector<int> dis(sz, INF);
    vis[id[A]] = true;
    dis[id[A]] = 0;
    queue<int> Q;
    Q.emplace(id[A]);
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : adj[now]) {
            if (vis[c]) continue;
            vis[c] = true;
            dis[c] = min(dis[c], dis[now] + 1);
            Q.push(c);
        }
    }
    if (dis[id[B]] == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << dis[id[B]] << '\n';
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