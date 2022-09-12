#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    ll ans;
    if (n == 1) {
        int res = m % 6;
        ans = (m / 6) * 6;
        if (res == 4) {
            ans += 2;
        } else if (res == 5) {
            ans += 4;
        }
    } else if (n == 2) {
        if (m == 2) {
            ans = 0;
        } else if (m == 3) {
            ans = 4; 
        } else if (m == 7) {
            ans = 12;
        } else {
            ans = m * 2;
        }
    } else {
        ans = ((n * m) / 2) * 2;
    }
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