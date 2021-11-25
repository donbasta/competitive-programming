#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int a, b, e, p;
    cin >> a >> b >> e >> p;
    vector<vector<int>> to(e), from(e);
    vector<int> in(e), out(e), d1(e), d2(e);
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        to[y].emplace_back(x);
        from[x].emplace_back(y);
        in[y]++;
        out[x]++;
    }
    queue<int> q1, q2;
    for (int i = 0; i < e; i++) {
        if (in[i] == 0) {
            q1.emplace(i);
            d1[i] = 1;
        }
        if (out[i] == 0) {
            q2.emplace(i);
            d2[i] = 1;
        }
    }
    while(!q1.empty()) {
        int now = q1.front();
        q1.pop();
        for (auto j : from[now]) {
            d1[j] += d1[now];
            in[j]--;
            if (in[j] == 0) {
                d1[j]++;
                q1.emplace(j);
            }
        }
    }
    while(!q2.empty()) {
        int now = q2.front();
        q2.pop();
        for (auto j : to[now]) {
            d2[j] += d2[now];
            out[j]--;
            if (out[j] == 0) {
                d2[j]++;
                q2.emplace(j);
            }
        }
    }
    for (int i = 0; i < e; i++) {
        cerr << i << ' ' << d1[i] << ' ' << d2[i] << '\n';
    }
    // vector<int> ans(3);
    // for (int i = 0; i < e; i++) {
    //     if (d1[i] >= b) {
    //         ans[2]++;
    //     }
    //     if (e - d2[i])
    // }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}