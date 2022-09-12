#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n + 1), x(m), pref(n + 2);
    p[0] = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pref[i] = pref[i - 1] + p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    ll ans = 0;

    ll t = (x[0] - 1) / 100;
    if (x[0] > 0) {
        ans = max(ans, pref[t + 1]);
    }
    t =  (x[m - 1] / 100) + 1;
    if (t <= n) {
        ans = max(ans, pref[n] - pref[t]);
    }

    for (int i = 0; i < m - 1; i++) {
        ll dis = x[i + 1] - x[i];
        ll rig = (dis - 1) / 200;
        ll j0 = ((x[i] / 100) + 1);
        ll j1 = min(n - 1, ((x[i + 1] - 1) / 100));
        for (ll j = j0; j <= j1; j++) {
            ll jr = min(j1, j0 + rig);
            ans = max(ans, pref[jr + 1] - pref[j]);
        }
    }

    cout << ans << '\n';
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