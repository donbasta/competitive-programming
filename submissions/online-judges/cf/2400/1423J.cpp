#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
ll m;

void solve() {
    cin >> m;
    ll mod = m % 4;
    m /= 4;
    m %= MOD;
    ll ans;
    if (mod == 0 || mod == 1) {
        ans = ((m + 1) * (m + 1)) % MOD;
    } else if (mod == 2 || mod == 3) {
        ans = ((m + 1) * (m + 2)) % MOD;
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