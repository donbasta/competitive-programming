#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, m;

void solve() {
    cin >> n >> m;
    ll on = n;
    if (m < n) {
        cout << 0 << '\n';
    } else {
        ll ans = 0;
        for (int j = 32; j >= 0; j--) {
            int a = (m >> j) & 1;
            int b = (n >> j) & 1;
            if (b == 0 && a == 1) {
                ans += (1LL << j);
                n |= (1LL << j);
            }
            if (b == 1 && a == 0) {
                break;
            }
        }
        if (n <= m) {
            for (int j = 0; j <= 32; j++) {
                int b = (n >> j) & 1;
                if (b == 0) {
                    ans += (1LL << j);
                    for (int k = j - 1; k >= 0; k--) {
                        int bc = (n >> k) & 1;
                        int bd = (on >> k) & 1;
                        if (bd != bc) ans -= (1LL << k);
                    }
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
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