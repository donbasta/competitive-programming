#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
const ll MOD = 1e9 + 7;

void solve() {
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ll cnt = n - 1;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll tmp = ar[i] * ar[i] % MOD;
        tmp = tmp * cnt % MOD;
        ans += tmp;
        ans %= MOD;
        cnt -= 2;
    }
    if (ans < 0) ans += MOD;
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