#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    int p = n * m;
    ll ans = 1;
    for (int i = 0; i < p - 1; i++) {
        ans = (ans * 2) % mod;
    }
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