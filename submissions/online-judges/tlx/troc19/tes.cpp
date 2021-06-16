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

ll inv(ll a) {
    return fpow(a, mod - 2);
}

void solve() {
    ll x = 8;
    ll y = inv(3);
    cout << x * y % mod << '\n';
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