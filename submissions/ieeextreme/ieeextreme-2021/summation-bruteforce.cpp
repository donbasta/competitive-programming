#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 1e6;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = (ret * a) % mod; }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    ll p, q, n, m;
    cin >> p >> q >> n >> m;

    if (p % m == 0) {
        cout << 0 << '\n';
        return;
    }
    ll ret = 0;
    ll ppow = 1;
    for (int i = 1; i <= n; i++) {
        ppow = (ppow * p) % m;
        ll tmp = (fpow(i, q, m) * ppow) % m;
        ret = (ret + tmp) % m;
    }
    ret %= m;
    if (ret < 0) ret += m;
    cout << ret << '\n';
    return;
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