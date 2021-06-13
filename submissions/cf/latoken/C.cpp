#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int n;

void solve() {
    cin >> n;
    vector<vector<int>> ar(2, vector<int>(n)), loc(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            --ar[i][j];
            loc[i][ar[i][j]] = j;
        }
    }
    ll ans = 1;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[ar[0][i]]) continue;
        int fi = ar[0][i];
        int cur = ar[0][i];
        int nx = ar[1][i];
        vis[cur] = 1;
        while (nx != fi) {
            cur = nx;
            nx = ar[1][loc[0][nx]];
            vis[cur] = 1;
        }
        ans = (ans * 2LL) % MOD;
    }
    cout << ans << '\n';
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