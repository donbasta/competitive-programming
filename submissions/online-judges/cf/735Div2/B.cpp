#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    ll ans = -INF;
    for (ll i = n - 1; i >= max(n - 1 - 2 * k, 1LL); i--) {
        for (ll j = i + 1; j <= n; j++) {
            ans = max(ans, i * j - k * (ar[i] | ar[j]));
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