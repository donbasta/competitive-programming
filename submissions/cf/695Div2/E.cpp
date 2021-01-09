#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tot = 0;
    int col = -1;
    for (auto e : cnt) {
        if (e.second >= 3) {
            tot++;
            col = e.first;
        }
    }
    if (tot > 1) {
        cout << 0 << '\n';
        return;
    }
    if (tot == 1) {
        vector<int> ve;
        for (int i = 1; i <= n; i++) {
            if (ar[i] == col) ve.push_back(i);
        }
        
    }
    if (tot == 0) {

    }
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