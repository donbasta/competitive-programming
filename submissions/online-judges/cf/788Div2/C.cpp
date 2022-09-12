#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n), a(n), b(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        ar[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        --b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        --d[i];
    }

    vector<bool> vis(n);
    vector<int> cyc;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        int len = 0;
        bool fixed = false;
        while (!vis[j]) {
            // cerr << j << ' ' << d[j] << '\n';
            len++;
            vis[j] = true;
            if (d[ar[j]] != -1) {
                fixed = true;
            }
            j = b[ar[j]];
        }
        // cerr << '\n';
        if (!fixed) {
            cyc.emplace_back(len);
        }
    }
    ll ans = 1;
    for (auto e : cyc) {
        // cerr << e << '\n';
        if (e > 1) {
            ans = (ans * 2) % MOD;
        }
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