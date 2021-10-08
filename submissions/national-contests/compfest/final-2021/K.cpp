#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, m, k, r, c;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = (ret * a) % MOD; }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void solve() {
    cin >> n >> m >> k >> r >> c;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ll pang = 0;
    if (ax == bx && ay == by) {
        pang = n * m;
    } else {
        pang = n * m - r * c;
    }
    ll ans = fpow(k, pang);
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