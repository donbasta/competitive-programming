#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
ll n, m, ans;

ll sum(ll a, ll b) {
    if (a > b) return 0;
    b %= MOD;
    a %= MOD;
    ll ret = ((b * (b + 1) / 2) - ((a - 1) * a / 2)) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

void solve() {
    cin >> n >> m;
    if (m > n) {
        ans = ((n % MOD) * ((m - n) % MOD)) % MOD;
        m = min (m, n);
    }
    ll sq = (ll) sqrt(n);
    for (ll i = 1; i <= sq; i++) {
        ll a = (n / i);
        ll b = (n / (i + 1));
        if (a <= b) continue;
        if (m <= b) continue;
        if (m > b && m <= a) a = m;
        ans = (ans + (n % MOD) * ((a - b) % MOD)) % MOD;
        ans = (ans - i * sum(b + 1, a)) % MOD;
    }
    ll bat = n / (sq + 1);
    for (ll i = 1; i <= min(m, bat); i++) {
        ans = (ans + (n % i) % MOD) % MOD;
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