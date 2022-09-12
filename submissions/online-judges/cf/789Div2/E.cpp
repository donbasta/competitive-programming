#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ca(n), cb(n), cc(n);
    for (int i = 0; i < n; i++) {
        cin >> ca[i];
        --ca[i];
        cc[ca[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> cb[i];
        --cb[i];
    }

    vector<bool> vis(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        int cyc = 0;
        while (!vis[j]) {
            cyc++;
            vis[j] = true;
            j = cc[cb[j]];
        }
        cnt += cyc / 2;
    }
    ll ans  = 2LL * cnt * (n - cnt);
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