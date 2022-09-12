#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1000;
bool vis[M + 5];
int dis[M + 5];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> B(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    cost: dis[B[i]], weight: C[i]
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue<int> Q;

    Q.emplace(1);
    dis[1] = 0;
    vis[1] = true;
    while (!Q.empty()) {
        auto node = Q.front();
        Q.pop();
        for (int x = 1; x <= node; x++) {
            int to = node + (node / x);
            if (to > M || vis[to]) continue;
            vis[to] = true;
            dis[to] = dis[node] + 1;
            Q.emplace(to);
        }
    }

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}