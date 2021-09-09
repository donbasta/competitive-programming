#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, x, k;
const ll mod = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    cin >> n >> x >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (k == 0) {
        int beda = 0;
        for (int i = 0; i < n - 1; i++) {
            beda += (ar[i] != ar[i + 1]);
        }
        cout << beda + 1 << '\n';
        return;
    }
    ll tot = (fpow(2, k) - 1) * (n - 1) + n;
    // cerr << tot << '\n';
    tot %= mod;
    ll ans = tot;
    ans -= (tot - 1) * fpow(x, mod - 2);
    ans %= mod;
    if (ans < 0) ans += mod;
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