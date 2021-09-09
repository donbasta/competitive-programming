#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int m;

void solve() {
    cin >> m;
    vector<ll> a(m + 1), b(m + 1), pb(m + 2), qa(m + 2);
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) {
        pb[i] = pb[i - 1] + b[i];
    }
    for (int i = m; i >= 1; i--) {
        qa[i] = qa[i + 1] + a[i];
    }
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) {
        ll cur = max(pb[i - 1], qa[i + 1]);
        ans = min(ans, cur);
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