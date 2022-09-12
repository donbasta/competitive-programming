#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    int R = 0, W = 0;
    for (int i = 0; i < m; i++) {
        int r, w;
        cin >> r >> w;
        R = max(r, R), W = max(w, W);
    }
    if (R + W > n) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    R = n - W;
    for (int i = 0; i < R; i++) {
        cout << 'R';
    }
    for (int i = 0; i < W; i++) {
        cout << 'W';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}