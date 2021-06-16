#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

ll n, m, k;

void solve() {
    cin >> n >> m >> k;
    n %= (mod - 1);
    m %= (mod - 1);
    if (k == 1 || (k == -1 && ((m + n) % 2 == 0))) {
        cout << fpow(2LL, (n + mod - 2) * (m + mod - 2));
    } else {
        cout << 0;
    }
    cout << '\n';
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