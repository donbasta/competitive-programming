#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

ll n, k;

void solve() {
    cin >> n >> k;
    ll p = fpow(2, n - 1);
    ll ans;
    if (n % 2 == 0) {
        ans = fpow(p - 1, k);
        for (int i = 0; i < k; i++) {
            ll tmp = (fpow(p - 1, i) * fpow(p * 2, k - i - 1)) % mod;
            ans = (ans + tmp) % mod;
        }
    } else {
        ans = fpow(p + 1, k);
    }
    if (ans < 0) ans += mod;
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